package server;

import dispatcher.Dispatchable;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public abstract class DispatcherSkeleton implements Dispatchable {
    private int port;

    public DispatcherSkeleton(int port) {
        this.port = port;
    }

    public void runSkeleton()
    {
        try {
            ServerSocket serverSocket = new ServerSocket(this.port);
            System.out.println ("Server attivo (*E*); avvio while loop... ");

            while(true){
                Socket socket = serverSocket.accept();
                Skeleton thread = new Skeleton(socket, this);
                thread.start();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

}
