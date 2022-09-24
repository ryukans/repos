package server;

import interfaces.Manager;
import interfaces.Subscribable;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server
{
    public static void main(String[] args)
    {
        try {
            Registry rmi = LocateRegistry.getRegistry();
            Manager managerServer = new ManagerServer();
            rmi.rebind(ManagerServer.CLASSNAME, managerServer);
        }
        catch(RemoteException e) {
            throw new RuntimeException(e);
        }
    }
}
