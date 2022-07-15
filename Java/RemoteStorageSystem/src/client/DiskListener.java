package client;

import interfaces.Logger;

import javax.jms.JMSException;
import javax.jms.MapMessage;
import javax.jms.Message;
import javax.jms.MessageListener;

public class DiskListener implements MessageListener
{
    private Proxy proxy;

    @Override
    public void onMessage(Message args)
    {
        System.out.println("Listener called");

        Thread thread = new Thread(() -> {
            MapMessage message = (MapMessage) args;

            System.out.println("Thread created");

            try{
                int data = message.getInt("data");
                int port = message.getInt("port");
                proxy = new Proxy(port);
                proxy.storeData(data);

                System.out.println("Data stored: " + data);
            }
            catch(JMSException e){
                throw new RuntimeException(e);
            }
        });

        thread.start();
    }
}
