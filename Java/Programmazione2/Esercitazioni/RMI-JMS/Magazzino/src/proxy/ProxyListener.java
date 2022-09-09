package proxy;

import interfaccia.IService;

import javax.jms.JMSException;
import javax.jms.MapMessage;
import javax.jms.Message;
import javax.jms.MessageListener;
import java.rmi.RemoteException;

public class ProxyListener implements MessageListener
{
    private IService service;

    public ProxyListener(IService service){
        this.service = service;
    }

    @Override
    public void onMessage(Message arg)
    {
        MapMessage message = (MapMessage) arg;

        try{
            String requestType = message.getString("requestType");

            if(requestType.equalsIgnoreCase("preleva")) {
                int id = service.preleva();

                Thread sender = new Thread(new Sender(id));
                sender.start();

                System.out.printf("[Receiver] - richiesta preleva %d\n", id);
            }
            else if(requestType.equalsIgnoreCase("deposita")){
                int id = message.getInt("id");

                service.deposita(id);

                System.out.printf("[Sender] - richiesta deposita %d\n", id);
            }
        }
        catch(JMSException | RemoteException e){
            throw new RuntimeException(e);
        }

    }
}
