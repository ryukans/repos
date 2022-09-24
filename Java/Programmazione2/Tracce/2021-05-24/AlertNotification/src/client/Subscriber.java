package client;

import interfaces.Manager;
import interfaces.Subscribable;
import server.ManagerServer;

import java.io.*;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Subscriber implements Subscribable
{
    private int componentId;
    private int port;

    public Subscriber(int componentId, int port)
    {
        this.componentId = componentId;
        this.port = port;
    }

    public int getComponentId() throws RemoteException {
        return componentId;
    }

    public void notifyAlert(int criticality) throws RemoteException
    {
        System.out.println("Critically level: " + criticality);

        try {
            PrintWriter out = new PrintWriter(
                    new BufferedWriter(
                            new FileWriter("./alert.txt", true)
                    )
            );

            out.println("Critically level: " + criticality);
            out.flush();
            out.close();
        }
        catch(IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args)
    {
        try {
            Registry rmi = LocateRegistry.getRegistry();
            Manager manager = (Manager) rmi.lookup(ManagerServer.CLASSNAME);
            int componentId = Integer.parseInt(args[0]);
            int port = Integer.parseInt(args[1]);

            Subscriber subscriber = new Subscriber(componentId, port);
            SubscriberSkeleton subscriberSkeleton = new SubscriberSkeleton(subscriber, port);

            manager.subscribe(componentId, port);
            subscriberSkeleton.runSkeleton();
        }
        catch(RemoteException | NotBoundException e) {
            throw new RuntimeException(e);
        }
    }
}
