package server;

import interfaccia.IService;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server
{
    public static void main(String[] args)
    {
        try {
            Registry rmi = LocateRegistry.getRegistry();
            IService service = new Service();

            rmi.rebind("servizio", service);

            System.out.println("[Server] - Avviato...");
        }
        catch(RemoteException e){
            throw new RuntimeException(e);
        }
    }
}
