package interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Observable extends Remote
{
    void notifyReading() throws RemoteException;
}
