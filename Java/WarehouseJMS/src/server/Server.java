package server;

import codaimpl.CodaCircolare;
import codaimpl.CodaWrapperSynchr;
import org.w3c.dom.Text;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.jms.*;
import java.util.Hashtable;

public class Server
{

    public static void main(String[] args)
    {
        CodaWrapperSynchr coda = new CodaWrapperSynchr(new CodaCircolare(10));
        Hashtable<String, String> prop = new Hashtable<>();

        prop.put("java.naming.factory.initial", "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
        prop.put("java.naming.provider.url", "tcp://127.0.0.1:61616");
        prop.put("queue.request", "request");


        try {
            Context context = new InitialContext();

            QueueConnectionFactory connectionFactory = (QueueConnectionFactory) context.lookup("QueueConnectionFactory");
            Queue qRequest = (Queue) context.lookup("request");
            Queue qReply = (Queue) context.lookup("reply");

            QueueConnection connection = connectionFactory.createQueueConnection();

            connection.start();

            QueueSession session = connection.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);

            QueueReceiver receiver = session.createReceiver(qRequest);

            final MapMessage message = (MapMessage) receiver.receive();

            new Thread(() -> {
                try {
                    String request = message.getString("request");
                    int id = message.getInt("id");

                    switch(request) {
                        case "deposit" -> {
                            coda.inserisci(id);
                        }
                        case "withdraw" -> {
                            QueueSession session1 = connection.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);
                            QueueSender sender = session1.createSender(qReply);

                            int idReply = coda.preleva();

                            TextMessage reply = idReply;

                        }
                    }

                }
                catch(JMSException e) {
                    throw new RuntimeException(e);
                }
            }).start();


            //receiver.setMessageListener(new Listener());
        }
        catch(NamingException | JMSException e) {
            throw new RuntimeException(e);
        }
    }
}
