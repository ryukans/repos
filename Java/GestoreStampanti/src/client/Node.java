package client;

import interfaces.dispatcher.IDispatcher;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class Node
{
    public static void main(String[] args)
    {
        IDispatcher dispatcher = null;
        try {
            dispatcher = (IDispatcher) LocateRegistry.getRegistry().lookup("dispatcher");
            Client[] tClients = new Client[5];

            for(int i = 0; i < 5; i++){
                tClients[i] = new Client(dispatcher);
                tClients[i].start();
            }
        }
        catch(RemoteException | NotBoundException e){
            throw new RuntimeException(e);
        }
    }
}
