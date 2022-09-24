package warehouse;

import client.Client;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Warehouse extends Remote
{
    void deposit(int id) throws RemoteException;
    int withdraw() throws RemoteException;
    void subscribe(Client client) throws RemoteException;
}
