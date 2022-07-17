package client;

import server.RemoteWarehouse;
import warehouse.Warehouse;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.util.Random;

public class Producer
{
    public static void main(String[] args)
    {
        try {
            Warehouse warehouse = (Warehouse) LocateRegistry.getRegistry().lookup(RemoteWarehouse.CLASSNAME);

            for(int i = 0; i < 3; i++) {
                String threadName = "Producer " + (i+1);

                new Thread(() -> {
                    System.out.printf("%s | Running\n", threadName);

                    int t = new Random().nextInt(1, 5);
                    try {
                        Thread.sleep(t*1000L);
                    }
                    catch(InterruptedException e) {
                        throw new RuntimeException(e);
                    }

                    int id = new Random().nextInt(1, 100);
                    try {
                        warehouse.deposit(id);

                        System.out.printf("%s | Deposited: %d\n", threadName, id);
                    } catch (RemoteException e) {
                        throw new RuntimeException(e);
                    }

                }, threadName).start();
            }
        }
        catch(RemoteException | NotBoundException e) {
            throw new RuntimeException(e);
        }
    }
}
