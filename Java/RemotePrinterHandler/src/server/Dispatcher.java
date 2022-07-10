package server;

import interfaces.Dispatchable;
import interfaces.Printer;

import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Vector;
import java.util.concurrent.Semaphore;

public class Dispatcher
        extends UnicastRemoteObject
        implements Dispatchable
{
    private Vector<Printer> printers;

    public Dispatcher() throws RemoteException
    {
        printers = new Vector<Printer>();
    }

    @Override
    public void addPrinter(Printer printer) throws RemoteException
    {
        printers.add(printer);
        //TODO
    }

    @Override
    public boolean printRequest(String docName) throws RemoteException
    {
        int i = 0;
        boolean served = false;
        while(i < printers.size() && !served)
            served = printers.get(i++).print(docName);

        return served;
    }
}
