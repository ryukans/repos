package client;

import server.RemoteWarehouse;
import warehouse.Warehouse;

import java.io.Serial;
import java.io.Serializable;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class Client implements Serializable
{
    @Serial
    private static final long serialVersionUID = -7060773381282434164L;
    private final Warehouse warehouse;
    public Client(Warehouse warehouse){
        this.warehouse = warehouse;
    }

    public void newItem() throws RemoteException {
        System.out.println("Client | Item withdrawn from warehouse: " + warehouse.withdraw());
    }

    public static void main(String[] args)
    {
        try {
            Warehouse warehouse = (Warehouse) LocateRegistry.getRegistry().lookup(RemoteWarehouse.CLASSNAME);


            Client c1 = new Client(warehouse);
            Client c2 = new Client(warehouse);
            Client c3 = new Client(warehouse);

            warehouse.subscribe(c1);
            warehouse.subscribe(c2);
            warehouse.subscribe(c3);

            System.out.println("Clients subscribed");
        }
        catch (RemoteException | NotBoundException e) {
            throw new RuntimeException(e);
        }
    }
}
