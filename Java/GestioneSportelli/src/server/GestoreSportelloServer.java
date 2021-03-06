package server;

import interfaces.IGestoreSportello;

import java.rmi.AccessException;
import java.rmi.NotBoundException;
import java.rmi.Remote;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class GestoreSportelloServer
{
    public static void main(String[] args)
    {
        try{
            Registry rmi = LocateRegistry.getRegistry();
            IGestoreSportello gestore = new GestoreSportello();

            rmi.rebind("gestore", gestore);

        } catch (RemoteException e) {
            e.printStackTrace();
        }
    }
}
