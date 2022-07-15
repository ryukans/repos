package server;

import service.ICounter;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public abstract class CounterSkeleton implements ICounter
{
    public void runSkeleton()
    {
        ServerSocket serverSocket = null;
        try{
           serverSocket = new ServerSocket(2500);
           System.out.println("Server open on 2500");

           while(true){
               Socket socket = serverSocket.accept();
               SkeletonThread st = new SkeletonThread(socket, this);
               st.start();
           }
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}
