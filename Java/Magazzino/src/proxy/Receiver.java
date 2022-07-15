package proxy;

import interfaccia.IService;

import javax.jms.*;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import java.net.http.WebSocket;
import java.sql.Connection;
import java.util.Hashtable;
import java.util.function.Consumer;

public class Receiver implements Runnable
{
    private IService service;
    public Receiver(IService service){
        this.service = service;
    }

    @Override
    public void run()
    {
        Hashtable<String, String> prop = new Hashtable<>();

        prop.put("java.naming.factory.initial", "org.apache.activemq.jndi.ActiveMQInitialContextFactory");
        prop.put("java.naming.provider.url", "tcp://127.0.0.1:61616");
        prop.put("queue.richiesta", "richiesta");


        try {
            Context context = new InitialContext(prop);

            QueueConnectionFactory connectionFactory = (QueueConnectionFactory) context.lookup("QueueConnectionFactory");
            Queue queue = (Queue) context.lookup("richiesta");

            QueueConnection connection = connectionFactory.createQueueConnection();
            connection.start();

            QueueSession session = connection.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);

            QueueReceiver receiver = (QueueReceiver) session.createReceiver(queue);

            ProxyListener listener = new ProxyListener(service);

            receiver.setMessageListener(listener);

            System.out.println("[Listener] - avviato...");
        }
        catch(NamingException | JMSException e) {
            throw new RuntimeException(e);
        }

    }
}
