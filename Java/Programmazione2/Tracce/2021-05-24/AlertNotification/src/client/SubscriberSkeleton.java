package client;

import interfaces.Subscribable;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.rmi.RemoteException;

public class SubscriberSkeleton implements Subscribable
{
    private final Subscribable subscriber;
    private final int port;

    public SubscriberSkeleton(Subscribable subscriber, int port) throws RemoteException
    {
        this.subscriber = subscriber;
        this.port = port;
    }

    public void runSkeleton()
    {
        try(ServerSocket serverSocket = new ServerSocket(this.port)) {
            //noinspection InfiniteLoopStatement
            while(true) {
                Socket socket = serverSocket.accept();
                Skeleton s = new Skeleton(this, socket);

                s.start();
            }
        }
        catch(IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void notifyAlert(int criticality) throws RemoteException {
        subscriber.notifyAlert(criticality);
    }
}
