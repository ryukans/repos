package storage;

import queue.MyQueue;
import queueImpl.CircularQueue;
import queueImpl.CircularQueueWrapper;

import javax.jms.*;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.util.Hashtable;

public class Storage
{
    public static void main(String[] args)
    {
        Hashtable<String, String> prop = new Hashtable<>();

        prop.put("java.naming.factory.initial", "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
        prop.put("java.naming.provider.url", "tcp://172.0.0.1:61616");
        prop.put("queue.Request", "Request");

        try {
            Context context = new InitialContext(prop);

            //Administrative objects
            QueueConnectionFactory connectionFactory = (QueueConnectionFactory) context.lookup("QueueConnectionFactory");
            Queue request = (Queue) context.lookup("Request");

            //Create connection using connection factory
            QueueConnection connection = connectionFactory.createQueueConnection();

            //Enabling connection explicitly in order to receive incoming messages.
            connection.start();

            //Create connection session, not transacted and auto acknowledge
            QueueSession session = connection.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);


            //Create receiver of the session
            QueueReceiver receiver = session.createReceiver(request);

            MyQueue queue = new CircularQueueWrapper(new CircularQueue(5));

            ServerListener listener = new ServerListener(connection, queue);

            receiver.setMessageListener(listener);

        }catch(NamingException | JMSException e){
            throw new RuntimeException(e);
        }
    }
}
