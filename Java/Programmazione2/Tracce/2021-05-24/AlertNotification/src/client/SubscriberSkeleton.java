package client;

import interfaces.Manager;
import interfaces.Subscribable;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.rmi.RemoteException;

public class SubscriberSkeleton implements Subscribable
{
    private Subscribable subscriber;
    private int port;

    public SubscriberSkeleton(Subscribable subscriber, int port) throws RemoteException
    {
        this.subscriber = subscriber;
        this.port = port;
    }

    public void runSkeleton()
    {
        try(ServerSocket serverSocket = new ServerSocket(this.port)) {
            Socket socket = null;
            while(true) {
                socket = serverSocket.accept();
                Skeleton s = new Skeleton(this, socket);

                s.start();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void notifyAlert(int criticality) throws RemoteException {
        subscriber.notifyAlert(criticality);
    }

}
