package server;

import client.Client;
import queue.buffer.CircularQueue;
import queue.monitor.QueueMonitor;
import warehouse.Warehouse;

import java.io.Serial;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Vector;

public class RemoteWarehouse
        extends UnicastRemoteObject
        implements Warehouse
{

    public static final String CLASSNAME = "RemoteWarehouse";
    @Serial
    private static final long serialVersionUID = -8650695043218846098L;
    private static final int MAXSIZE = 10;
    private final QueueMonitor idList;
    private final Vector<Client> clients;


    public RemoteWarehouse() throws RemoteException
    {
        idList = new QueueMonitor(new CircularQueue(MAXSIZE));
        clients = new Vector<>();
    }

    @Override
    public void deposit(int id) throws RemoteException
    {
        idList.push(id);

        System.out.println("Server | Deposited item: " + id);

        // notify
        for(Client c : clients)
            c.newItem();

        System.out.println("Server | clients notified");
    }

    @Override
    public int withdraw() throws RemoteException {
        return idList.pop();
    }

    @Override
    public void subscribe(Client client) throws RemoteException {
        clients.add(client);
    }

}
