package client;

import javax.jms.JMSException;
import javax.jms.MapMessage;
import javax.jms.Message;
import javax.jms.MessageListener;

public class ClientListener implements MessageListener
{
    @Override
    public void onMessage(Message arg)
    {
        MapMessage message = (MapMessage) arg;

        try {
            System.out.printf("[Receiver Client] - Ricevuta risposta con id %d", message.getInt("id"));
        } catch (JMSException e) {
            throw new RuntimeException(e);
        }
    }
}
