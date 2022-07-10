package server;

import interfaces.Dispatchable;
import interfaces.Printer;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class RemotePrinterServer
{
    public static void main(String[] args)
    {
        try {
            Dispatchable dispatcher = (Dispatchable)LocateRegistry.getRegistry().lookup("dispatcher");
            Printer printer = new RemotePrinter();

            dispatcher.addPrinter(printer);
        }
        catch(RemoteException e){
            e.printStackTrace();
        } catch (NotBoundException e) {
            throw new RuntimeException(e);
        }

    }
}
