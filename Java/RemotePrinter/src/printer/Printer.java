package printer;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Printer extends Remote
{
    void printDoc(String docName) throws RemoteException;
}
