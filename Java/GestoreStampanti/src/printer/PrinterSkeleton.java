package printer;

import interfaces.dispatcher.IDispatcher;
import interfaces.printer.IPrinter;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class PrinterSkeleton implements IPrinter
{
    private IPrinter printer;
    private int port;

    public PrinterSkeleton(IPrinter printer, int port)
    {
        this.printer = printer;
        this.port = port;
    }

    public void runSkeleton()
    {
        ServerSocket serverSocket = null;
        try{
            serverSocket = new ServerSocket(this.port);

            while(true){
                Socket socket = serverSocket.accept();
                Skeleton thread = new Skeleton(socket, this);
                thread.start();
            }
        }
        catch(IOException e){
            throw new RuntimeException(e);
        }
    }

    @Override
    public boolean print(String docName){
        return printer.print(docName);
    }
}
