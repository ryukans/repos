package server;

import service.ICounter;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public abstract class CounterSkeleton implements ICounter
{

    ServerSocket serverSocket = null;
    Socket socket = null;

    public void runSkeleton()
    {
        try{
           serverSocket = new ServerSocket(2500);
           System.out.println("Server open on 2500");

           while(true){
               this.socket = serverSocket.accept();
               SkeletonThread st = new SkeletonThread(this.socket, this);
               st.start();
           }
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}
