package control;

import java.lang.IllegalStateException;
import java.util.Hashtable;
import java.util.Random;
import javax.jms.*;
import javax.naming.*;

public class Control
{
    private static final int MAXMESSAGES = 20;

    public static void main(String[] args)
    {
        Hashtable<String, String> prop = new Hashtable<>();

        prop.put("java.naming.factory.initial", "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
        prop.put("java.naming.provider.url", "tcp://127.0.0.1:61616");
        prop.put("topic.commands", "commands");

        try{
            Context context = new InitialContext(prop);

            TopicConnectionFactory connectionFactory = (TopicConnectionFactory) context.lookup("TopicConnectionFactory");
            Topic topic = (Topic) context.lookup("commands");

            TopicConnection connection = connectionFactory.createTopicConnection();
            TopicSession session = connection.createTopicSession(false, Session.AUTO_ACKNOWLEDGE);

            TopicPublisher pub = session.createPublisher(topic);

            TextMessage message = session.createTextMessage();

            for(int i = 0; i < MAXMESSAGES; i++){
                String command;
                int commandId = new Random().nextInt(1, 3);

                switch(commandId){
                    case 1 -> command = "start";
                    case 2 -> command = "stop";
                    case 3 -> command = "read";
                    default -> throw new IllegalStateException("Unexpected value: " + commandId);
                }

                message.setText(command);
                pub.publish(message);

                System.out.printf("Published command %d: %s\n", i, command);

                Thread.sleep(1000L);
            }
        }
        catch(NamingException | JMSException | InterruptedException e){
            throw new RuntimeException(e);
        }

        System.out.println("Control off");
    }
}
