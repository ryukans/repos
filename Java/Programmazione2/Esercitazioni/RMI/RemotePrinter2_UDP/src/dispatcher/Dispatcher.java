package dispatcher;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Dispatcher extends Remote
{
    void addPrinter(String host, int port) throws RemoteException;
    boolean printRequest(String docName) throws RemoteException;
}
