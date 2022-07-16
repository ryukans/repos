package server;

import printer.Printer;

import java.io.*;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class RemotePrinter
        extends UnicastRemoteObject
        implements Printer
{
    @Serial
    private static final long serialVersionUID = 5385858117511484576L;
    private int requests;
    public RemotePrinter() throws RemoteException {
        requests = 1;
    }

    public synchronized void printDoc(String docName) throws RemoteException
    {
        while(requests <= 0){
            try {
                wait();
                --requests;
            }
            catch(InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        try {
            PrintWriter out = new PrintWriter(new FileWriter("./log.txt", true));

            System.out.println("Document name: " + docName);
            out.println("Document name: " + docName);
            out.flush();
            out.close();

            ++requests;
            notifyAll();
        }
        catch(IOException e) {
            throw new RuntimeException(e);
        }
    }
}
