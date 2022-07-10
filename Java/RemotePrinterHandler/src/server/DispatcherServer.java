package server;

import interfaces.Dispatchable;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class DispatcherServer
{
    public static void main(String[] args)
    {
        try{
            Registry rmi = LocateRegistry.getRegistry();
            Dispatchable dispatcher = new Dispatcher();

            rmi.rebind("dispatcher", dispatcher);
        }
        catch(RemoteException e){
            e.printStackTrace();
        }
    }
}