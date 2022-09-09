package server;

import dispatcher.ObserverDispatcher;
import interfaces.Dispatcher;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server
{
    public static void main(String[] args)
    {
        try{
            Dispatcher dispatcher = new ObserverDispatcher();
            Registry rmi = LocateRegistry.getRegistry();

            rmi.rebind(ObserverDispatcher.CLASSNAME, dispatcher);
        }
        catch(RemoteException e){
            throw new RuntimeException(e);
        }

    }
}
