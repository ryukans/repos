package interfaces;

import dispatcher.Reading;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Dispatchable extends Remote
{
    void setReading(Readable reading) throws RemoteException;
    Readable getReading() throws RemoteException;
    void attach(Observable observer, String type) throws RemoteException;
}
