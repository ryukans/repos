package client;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.jms.*;
import java.util.Hashtable;
import java.util.Random;

public class Client
{
    public static void main(String[] args)
    {
        Hashtable<String, String> prop = new Hashtable<>();

        prop.put("java.naming.factory.initial", "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
        prop.put("java.naming.provider.url", "tcp://127.0.0.1:61616");
        prop.put("queue.request", "request");

        try {
            Context context = new InitialContext(prop);

            QueueConnectionFactory connectionFactory = (QueueConnectionFactory) context.lookup("QueueConnectionFactory");
            Queue queue = (Queue) context.lookup("request");

            QueueConnection connection = connectionFactory.createQueueConnection();
            QueueSession session = connection.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);

            QueueSender sender = session.createSender(queue);
            MapMessage message = session.createMapMessage();

            for(int i = 0; i < 10; i++) {
                String request = (Math.random() < 0.5) ? "deposit" : "withdraw";
                int id = new Random().nextInt(100);

                message.setString("request", request);
                message.setInt("id", id);

                sender.send(message);
            }
        }
        catch(NamingException | JMSException e) {
            throw new RuntimeException(e);
        }
    }
}
