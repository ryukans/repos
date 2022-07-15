package sensor;


import com.sun.istack.NotNull;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.util.Hashtable;
import java.util.Vector;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class Sensor
{
    private static Sensor sensor;

    private String[] commandsBuffer;
    private static final int SIZE = 5;
    private int count;
    private int head;
    private int tail;
    Lock mutex;
    Condition producer;
    Condition consumer;

    private void initializeSensor()
    {
        commandsBuffer = new String[SIZE];
        count = head = tail = 0;
        mutex = new ReentrantLock();
        producer = mutex.newCondition();
        consumer = mutex.newCondition();
    }

    /*
    * Singleton
    * */
    protected static Sensor getSensor()
    {
        if(sensor == null)
            sensor = new Sensor();

        return sensor;
    }


    public static void main(String[] args)
    {
        Hashtable<String, String> prop = new Hashtable<>();

        prop.put("java.naming.factory.initial", "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
        prop.put("java.naming.provided.url", "tcp://127.0.0.1:61616");
        prop.put("topic.commands", "commands");

        try{
            Context context = new InitialContext(prop);

            TopicConnectionFactory connectionFactory = (TopicConnectionFactory) context.lookup("TopicConnectionFactory");
            Topic topic = (Topic) context.lookup("commands");

            TopicConnection connection = connectionFactory.createTopicConnection();
            TopicSession session = connection.createTopicSession(false, Session.AUTO_ACKNOWLEDGE);

            connection.start();

            TopicSubscriber sub = session.createSubscriber(topic);

            getSensor().initializeSensor();
            System.out.println("Sensor initialized");

            Executor executor = new Executor();
            executor.start();

            sub.setMessageListener(new Listener());

        }
        catch(NamingException | JMSException e){
            throw new RuntimeException(e);
        }
    }

    protected void put(@NotNull String command)
    {
        mutex.lock();

        try{
            while(count == SIZE){
                System.out.println("Buffer full");
                try{
                    producer.await();
                }
                catch(InterruptedException e){
                    throw new RuntimeException(e);
                }
            }

            commandsBuffer[tail] = command;
            tail = (tail+1)%SIZE;
            ++count;

            consumer.signal();
        }
        finally{
            mutex.unlock();
        }
    }

    protected String pop()
    {
        String command = null;

        mutex.lock();

        try{
            while(count == 0){
                System.out.println("Buffer is empty");
                try{
                    consumer.await();
                }
                catch(InterruptedException e){
                    throw new RuntimeException(e);
                }
            }

            command = commandsBuffer[head];
            head = (head+1)%SIZE;
            --count;

            producer.signal();
        }
        finally{
            mutex.unlock();
        }

        return command;
    }

    protected boolean isFull(){
        return count == SIZE;
    }

    protected boolean isEmpty(){
        return count == 0;
    }


    protected Vector<String> takeAll()
    {
        Vector<String> commands = new Vector<>();

        while(!isEmpty())
            commands.add(pop());

        return commands;
    }
}
