package server;

import warehouse.Warehouse;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server
{
    public static void main(String[] args)
    {
        try {
            Warehouse warehouse = new RemoteWarehouse();
            Registry rmi = LocateRegistry.getRegistry();

            rmi.rebind(RemoteWarehouse.CLASSNAME, warehouse);
        }
        catch(RemoteException e) {
            throw new RuntimeException(e);
        }
    }
}
