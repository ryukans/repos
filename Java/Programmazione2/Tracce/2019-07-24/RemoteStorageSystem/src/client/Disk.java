package client;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.util.Hashtable;
import java.util.Random;

public class Disk
{
    public static void main(String[] args)
    {
        Hashtable<String, String> prop = new Hashtable<>();

        prop.put("java.naming.factory.initial", "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
        prop.put("java.naming.provider.url", "tcp://127.0.0.1:61616");
        prop.put("queue.login", "login");

        try{
            Context context = new InitialContext(prop);

            QueueConnectionFactory connectionFactory = (QueueConnectionFactory) context.lookup("QueueConnectionFactory");
            Queue queue = (Queue) context.lookup("login");

            QueueConnection connection = connectionFactory.createQueueConnection();


            QueueSession session = connection.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);


            QueueReceiver receiver = session.createReceiver(queue);
            receiver.setMessageListener(new DiskListener());

            connection.start();
        }
        catch(NamingException | JMSException e){
            throw new RuntimeException(e);
        }
    }
}
