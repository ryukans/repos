package server;

import dispatcher.Dispatcher;
import interfaces.Dispatchable;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server
{
    public static void main(String[] args)
    {
        try{
            Dispatchable dispatcher = new Dispatcher();
            Registry rmi = LocateRegistry.getRegistry();

            rmi.rebind(Dispatcher.CLASSNAME, dispatcher);
        }
        catch(RemoteException e){
            throw new RuntimeException(e);
        }

    }
}
