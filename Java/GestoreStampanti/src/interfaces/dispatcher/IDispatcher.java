package interfaces.dispatcher;

import interfaces.printer.IPrinter;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface IDispatcher extends Remote
{
    void addPrinter(String host, int port) throws RemoteException;
    boolean printRequest(String docName) throws RemoteException;
}
