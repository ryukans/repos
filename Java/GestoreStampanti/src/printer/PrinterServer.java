package printer;

import interfaces.dispatcher.IDispatcher;
import interfaces.printer.IPrinter;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class PrinterServer
{
    public static void main(String[] args)
    {
        IPrinter printer = new Printer();
        PrinterSkeleton server = new PrinterSkeleton(printer, 8000);
        try {
            Registry rmi = LocateRegistry.getRegistry();

            IDispatcher dispatcher = (IDispatcher) rmi.lookup("dispatcher");

            dispatcher.addPrinter("172.0.0.1", 8000);

            server.runSkeleton();
        } catch (RemoteException | NotBoundException e) {
            throw new RuntimeException(e);
        }
    }
}
