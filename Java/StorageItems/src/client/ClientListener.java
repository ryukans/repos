package client;

import javax.jms.JMSException;
import javax.jms.MapMessage;
import javax.jms.Message;
import javax.jms.MessageListener;
import java.util.Map;

public class ClientListener implements MessageListener
{
    public ClientListener()
    {}

    @Override
    public void onMessage(Message message)
    {
        MapMessage mapMessage = (MapMessage) message;

        try{
            System.out.println("[Client] - Item received: " + mapMessage.getInt("itemId"));
        }
        catch(JMSException e){
            throw new RuntimeException(e);
        }
    }
}
