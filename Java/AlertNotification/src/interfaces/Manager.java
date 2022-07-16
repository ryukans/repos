package interfaces;

import client.AlertNotification;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Manager extends Remote
{
    void subscribe(int componentId, int port) throws RemoteException;
    void sendNotification(AlertNotification notification) throws RemoteException;
}
