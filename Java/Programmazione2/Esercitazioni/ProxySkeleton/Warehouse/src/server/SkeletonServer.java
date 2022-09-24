package server;

import interfaces.Warehouse;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public abstract class SkeletonServer implements Warehouse
{
    private int port;

    public SkeletonServer(int port){
        this.port = port;
    }

    public void runSkeleton()
    {
        try{
            ServerSocket serverSocket = new ServerSocket(this.port);
            Socket socket = null;
            while(true){
               socket = serverSocket.accept();
               Skeleton worker = new Skeleton(socket, this);
               worker.start();
            }
        }
        catch(IOException e){
            throw new RuntimeException(e);
        }
    }

}
