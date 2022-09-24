package client;

import interfaces.Manager;
import server.ManagerServer;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.util.Random;

public class Generator
{
    public static void main(String[] args)
    {
        try {
            Manager manager = (Manager) LocateRegistry.getRegistry().lookup(ManagerServer.CLASSNAME);

            for(int i = 0; i < 3; i++) {
                new Thread(() -> {
                    int componentId = 5;
                    int criticality = new Random().nextInt(1, 3);

                    try {
                        manager.sendNotification(new AlertNotification(componentId, criticality));
                    }
                    catch(RemoteException e) {
                        throw new RuntimeException(e);
                    }
                }).start();
            }
        }
        catch(RemoteException | NotBoundException e) {
            throw new RuntimeException(e);
        }
    }
}
