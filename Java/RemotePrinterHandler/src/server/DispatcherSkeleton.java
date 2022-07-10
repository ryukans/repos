package server;

import interfaces.Dispatchable;
import interfaces.Printer;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.rmi.RemoteException;

public class DispatcherSkeleton
{
    private Dispatchable dispatcher;

    public DispatcherSkeleton(Dispatchable dispatcher){
        this.dispatcher = dispatcher;
    }

    public void runSkeleton()
    {
        //ServerSocket serverSocket = null;
        Socket socket = null;

        try(ServerSocket serverSocket = new ServerSocket(2500)){
            //serverSocket = new ServerSocket(2500);
            while(true){
                socket = serverSocket.accept();
                new Skeleton(socket, this.dispatcher).start();
            }
        }
        catch(IOException e){
            throw new RuntimeException(e);
        }
    }

    public void addPrinter(Printer printer) throws RemoteException {
        this.dispatcher.addPrinter(printer);
    }

    public void printRequest(String docName) throws RemoteException {
        this.dispatcher.printRequest(docName);
    }
}
