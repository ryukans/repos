package server;

import client.AlertNotification;
import client.Subscriber;
import client.SubscriberSkeleton;
import interfaces.Manager;
import interfaces.Subscribable;

import javax.sound.midi.SysexMessage;
import java.io.Serial;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;
import java.util.HashMap;
import java.util.Map;
import java.util.Vector;
import java.util.concurrent.Semaphore;

public class ManagerServer
        extends UnicastRemoteObject
        implements Manager
{
    @Serial
    private static final long serialVersionUID = 3396653297645375487L;
    public static final String CLASSNAME = "ManagerServer";
    private HashMap<Integer, Proxy> subs;
    private Semaphore mutex;


    public ManagerServer() throws RemoteException
    {
        subs = new HashMap<>();
        mutex = new Semaphore(1);
    }

    public void subscribe(int componentId, int port) throws RemoteException {
        subs.put(componentId, new Proxy("127.0.0.1", port));
    }

    public void sendNotification(AlertNotification notification) throws RemoteException
    {
        try {
            mutex.acquire();
        }
        catch(InterruptedException e) {
            throw new RuntimeException(e);
        }

        for(HashMap.Entry<Integer, Proxy> entry : subs.entrySet()) {
            int componentId = entry.getKey();
            Proxy subscriber = entry.getValue();
            if(componentId == notification.getComponentId())
                subscriber.notifyAlert(notification.getCriticality());
        }

        mutex.release();
    }
}
