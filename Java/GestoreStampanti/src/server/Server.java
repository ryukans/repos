package server;

import interfaces.dispatcher.IDispatcher;
import interfaces.printer.IPrinter;
import printer.Printer;
import printer.PrinterSkeleton;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server
{
    public static void main(String[] args)
    {
        try {
            Registry rmi = LocateRegistry.getRegistry();
            IDispatcher dispatcher = new Dispatcher();

            rmi.rebind("dispatcher", dispatcher);

            dispatcher.addPrinter("127.0.0.1", 8000);
        }
        catch(RemoteException e){
            throw new RuntimeException(e);
        }

    }
}
