package interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Subscribable extends Remote
{
    void notifyAlert(int criticality) throws RemoteException;
}
