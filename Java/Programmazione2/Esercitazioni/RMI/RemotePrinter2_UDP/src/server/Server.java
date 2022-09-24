package server;

import dispatcher.Dispatcher;
import dispatcher.PrinterDispatcher;
import dispatcher.PrinterProxy;
import printer.Printer;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class Server
{
    public static void main(String[] args)
    {
        try {
            System.out.println("Server | Online");

            final String host = args[0];
            final int port = Integer.parseInt(args[1]);
            Dispatcher dispatcher = (Dispatcher) LocateRegistry.getRegistry().lookup(PrinterDispatcher.CLASSNAME);
            RemotePrinterSkeleton remotePrinter = new RemotePrinterSkeleton(new RemotePrinter(), port);

            dispatcher.addPrinter(host, port);
            remotePrinter.runSkeletonUDP();
        }
        catch(RemoteException | NotBoundException e) {
            throw new RuntimeException(e);
        }
    }
}
