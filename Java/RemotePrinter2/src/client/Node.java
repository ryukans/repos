package client;

import dispatcher.Dispatcher;
import dispatcher.PrinterDispatcher;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.util.Random;

public class Node
{
    public static void main(String[] args)
    {
        try {
            Dispatcher dispatcher = (Dispatcher) LocateRegistry.getRegistry().lookup(PrinterDispatcher.CLASSNAME);

            for (int i = 0; i < 3; i++) {
                String nodeName = "Node " + (i+1);
                new Thread(() -> {
                    try {
                        System.out.printf("%s | Running\n", nodeName);

                        String docName = "doc" + new Random().nextInt(1, 10);

                        dispatcher.printRequest(docName);
                        Thread.sleep(3000L);
                    }
                    catch(RemoteException | InterruptedException e) {
                        throw new RuntimeException(e);
                    }
                }, nodeName).start();
            }
        }
        catch(RemoteException | NotBoundException e) {
            throw new RuntimeException(e);
        }
    }
}
