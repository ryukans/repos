package proxy;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.util.Hashtable;

public class Sender implements Runnable
{
    private int id;

    public Sender(int id){
        this.id = id;
    }

    @Override
    public void run()
    {
        Hashtable<String, String> prop = new Hashtable<>();

        prop.put("java.naming.factory.initial", "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
        prop.put("java.naming.provider.url", "tcp://127.0.0.1:61616");
        prop.put("queue.risposta", "risposta");

        try {
            Context context = new InitialContext(prop);

            QueueConnectionFactory connectionFactory = (QueueConnectionFactory) context.lookup("QueueConnectionFactory");
            Queue queue = (Queue) context.lookup("risposta");

            QueueConnection connection = connectionFactory.createQueueConnection();

            QueueSession session = connection.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);

            QueueSender sender = session.createSender(queue);

            MapMessage message = session.createMapMessage();

            message.setInt("id", id);
            sender.send(message);


        } catch (NamingException | JMSException e) {
            throw new RuntimeException(e);
        }

    }
}
