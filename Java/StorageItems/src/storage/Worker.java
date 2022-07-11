package storage;

import queue.MyQueue;

import javax.jms.*;
import java.util.Map;

public class Worker extends Thread
{
    private MyQueue queue;
    private MapMessage message;
    private QueueConnection connection;

    public Worker(MyQueue queue, MapMessage message, QueueConnection connection)
    {
        this.queue = queue;
        this.message = message;
        this.connection = connection;
    }

    public void run()
    {
        try {
            String op = message.getString("request");
            int item = message.getInt("itemId");

            switch(op){
                case "deposit" -> {
                    System.out.println("[Worker] - deposit on storage: " + item);
                    queue.insert(item);
                }
                case "withdraw" -> {
                    int id = queue.get();
                    System.out.println("[Worker] - withdraw from storage: " + id);

                    QueueSession session = connection.createQueueSession(false, Session.AUTO_ACKNOWLEDGE);

                    QueueSender sender = session.createSender((Queue) message.getJMSReplyTo());

                    MapMessage replyMessage = session.createMapMessage();
                    replyMessage.setString("op", "idWithdrawn");
                    replyMessage.setInt("itemId", id);

                    sender.send(replyMessage);

                    sender.close();
                    session.close();
                }
                default -> System.out.println("[Worker] - operation <" + op + "> is not valid");
            }
        }
        catch(JMSException e){
            throw new RuntimeException(e);
        }
    }
}
