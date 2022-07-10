package server;

import java.net.*;
import java.io.*;

import dispatcher.*;

public abstract class DispatcherSkeleton implements Dispatchable
{
    private int port;

    public DispatcherSkeleton(int port){
        this.port = port;
    }

    public void runSkeleton()
    {
        try{
            ServerSocket server = new ServerSocket(port);

            System.out.println ("Server attivo (*E*); avvio while loop... ");

            while(true){
                Socket s = server.accept();
                Skeleton t = new Skeleton(s, this);
                t.start();
            }
        }
        catch(IOException e){
            e.printStackTrace();
        }

    }


}
