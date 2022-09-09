package client;

import javax.jms.JMSException;
import javax.jms.MapMessage;
import javax.jms.Message;
import javax.jms.MessageListener;

public class DiskListener implements MessageListener
{
    private ProxyLogger proxy;

    @Override
    public void onMessage(Message args)
    {
        System.out.println("Listener called");

        new Thread(() -> {
            MapMessage message = (MapMessage) args;

            System.out.println("Thread created");

            try{
                int data = message.getInt("data");
                int port = message.getInt("port");
                proxy = new ProxyLogger(port);
                proxy.storeData(data);

                System.out.println("Data stored: " + data);
            }
            catch(JMSException e){
                throw new RuntimeException(e);
            }
        }).start();
    }
}
