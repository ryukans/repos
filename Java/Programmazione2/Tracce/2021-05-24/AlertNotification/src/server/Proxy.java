package server;

import interfaces.Subscribable;

import java.io.*;
import java.net.Socket;
import java.rmi.RemoteException;

public class Proxy implements Subscribable
{
    private String host;
    private int port;

    public Proxy(String host, int port)
    {
        this.host = host;
        this.port = port;
    }

    @Override
    public void notifyAlert(int criticality)
    {
        try(Socket socket = new Socket(this.host, this.port)) {
            DataOutputStream out = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );

            out.writeUTF("notifyAlert");
            out.writeInt(criticality);

            out.close();
        }
        catch(IOException e) {
            throw new RuntimeException(e);
        }
    }

}
