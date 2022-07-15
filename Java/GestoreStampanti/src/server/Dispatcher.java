package server;

import interfaces.dispatcher.IDispatcher;
import interfaces.printer.IPrinter;
import printer.Printer;

import java.io.Serial;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Vector;
import java.util.concurrent.Semaphore;

public class Dispatcher
        extends UnicastRemoteObject
        implements IDispatcher
{
    @Serial
    private static final long serialVersionUID = -3549284255644804843L;

    private Vector<IPrinter> stampanti;

    public Dispatcher() throws RemoteException{
        stampanti = new Vector<>();
    }

    @Override
    public void addPrinter(String host, int port) throws RemoteException{
        stampanti.add(new PrinterProxy(host, port));
    }

    @Override
    public boolean printRequest(String docName) throws RemoteException
    {
        int i = 0;
        boolean found = false;
        while(i < stampanti.size() && !found)
            found = stampanti.get(i++).print(docName);

        return found;
    }
}
