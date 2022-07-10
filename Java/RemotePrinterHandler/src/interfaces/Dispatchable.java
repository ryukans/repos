package interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Dispatchable extends Remote
{
    void addPrinter(Printer printer) throws RemoteException;
    boolean printRequest(String docName) throws RemoteException;

}
