package client;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.util.Hashtable;
import java.util.Map;
import java.util.Random;

public class Client
{
    private static final int N = 10;

    public static void main(String[] args)
    {
        Hashtable<String, String> prop = new Hashtable<>();

        prop.put("java.naming.factory.initial", "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
        prop.put("java.naming.provider.url", "tcp://127.0.0.1:61616");
        prop.put("queue.Request", "Request");
        prop.put("queue.Reply", "Reply");

        try{
            Context context = new InitialContext(prop);

            QueueConnectionFactory connectionFactory = (QueueConnectionFactory) context.lookup("QueueConnection");
            Queue request = (Queue) context.lookup("request");
            Queue reply = (Queue) context.lookup("reply");

            QueueConnection connection = connectionFactory.createQueueConnection();

            QueueSession session = connection.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);

            QueueReceiver receiver = session.createReceiver(reply);

            ClientListener listener = new ClientListener();

            receiver.setMessageListener(listener);

            QueueSender sender = session.createSender(request);
            MapMessage message = session.createMapMessage();
            for(int i = 0; i < N; i++){
                if(Math.random() < 0.5){
                    message.setString("op", "deposit");
                    int id = new Random().nextInt(10);
                    message.setInt("itemId", id);

                }
                else{
                    message.setString("op", "withdraw");
                }
                message.setJMSReplyTo(reply);
                sender.send(message);
            }
        }
        catch(NamingException | JMSException e){
            throw new RuntimeException(e);
        }
    }
}
