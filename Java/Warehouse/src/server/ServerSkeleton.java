package server;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class ServerSkeleton extends TechWarehouse
{
    private int port;

    public ServerSkeleton(int port){
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
            }
        }
        catch(IOException e){
            throw new RuntimeException(e);
        }
    }

}
