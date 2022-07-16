package server;

import printer.Printer;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Server
{
    public static void main(String[] args)
    {
        try {
            Registry rmi = LocateRegistry.getRegistry();
            String printerName = args[0];
            Printer printer = new RemotePrinter();

            System.out.println("Server | Binding...");

            rmi.rebind(printerName, printer);

            System.out.println("Server | Online");
        }
        catch(RemoteException e) {
            throw new RuntimeException(e);
        }
    }
}
