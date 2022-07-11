package storage;

import queue.MyQueue;

import javax.jms.Message;
import javax.jms.MapMessage;
import javax.jms.MessageListener;
import javax.jms.QueueConnection;

public class ServerListener implements MessageListener
{
    private QueueConnection connection;
    private MyQueue queue;

    public ServerListener(QueueConnection connection, MyQueue queue)
    {
        this.connection = connection;
        this.queue = queue;
    }

    @Override
    public void onMessage(Message message)
    {
        MapMessage mapMessage = (MapMessage) message;

        Worker thread = new Worker(queue, mapMessage, connection);
        thread.start();
    }
}
