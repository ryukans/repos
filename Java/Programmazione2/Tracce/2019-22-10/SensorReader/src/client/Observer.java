package client;

import dispatcher.ObserverDispatcher;
import dispatcher.Reading;
import interfaces.Dispatcher;
import interfaces.Observable;

import java.io.*;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class Observer
        extends UnicastRemoteObject
        implements Observable
{
    @Serial
    private static final long serialVersionUID = -8650330264164926164L;
    private final Dispatcher dispatcher;

    public Observer(Dispatcher dispatcher) throws RemoteException{
        this.dispatcher = dispatcher;
    }

    @Override
    public void notifyReading() throws RemoteException
    {
        Reading instance = (Reading) dispatcher.getReading();

        System.out.println("Notifying observers");
        try{
            PrintWriter out = new PrintWriter(
                    new BufferedWriter(
                            new FileWriter("./log.txt", true)
                    )
            );

            out.printf("Reading <%s, %d>\n", instance.getType(), instance.getValue());
            out.flush();
            out.close();
        }
        catch(IOException e){
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args)
    {
        try {
            Registry rmi = LocateRegistry.getRegistry();
            Dispatcher dispatcher = (Dispatcher) rmi.lookup(ObserverDispatcher.CLASSNAME);

            Observable observer = new Observer(dispatcher);

            dispatcher.attach(observer, args[0]);
        }
        catch(RemoteException | NotBoundException e){
            throw new RuntimeException(e);
        }
    }
}
