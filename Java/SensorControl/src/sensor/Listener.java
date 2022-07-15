package sensor;

import javax.jms.*;

public class Listener implements MessageListener
{
    @Override
    public void onMessage(Message arg)
    {
        TextMessage message = (TextMessage) arg;
        Manager manager = new Manager(message);

        manager.start();
    }
}
