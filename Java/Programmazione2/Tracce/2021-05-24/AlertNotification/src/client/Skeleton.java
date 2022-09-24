package client;

import interfaces.Subscribable;

import java.io.BufferedOutputStream;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class Skeleton extends Thread
{
    private final Subscribable subscriber;
    Socket socket;

    public Skeleton(Subscribable subscriber, Socket socket)
    {
        this.subscriber = subscriber;
        this.socket = socket;
    }

    @Override
    public void run()
    {
        try {
            DataOutputStream out = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );
            DataInputStream in = new DataInputStream(
                    new DataInputStream(socket.getInputStream())
            );

            String method = in.readUTF();

            if(method.equals("notifyAlert")) {
                int port = in.readInt();
                subscriber.notifyAlert(port);
            }
            else {
                System.out.println("Invalid method");
                throw new IllegalStateException();
            }

            out.close();
            in.close();
        }
        catch(IOException e) {
            throw new RuntimeException(e);
        }
    }
}
