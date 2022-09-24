package server;

import interfaces.Subscribable;

import java.io.*;

import java.net.Socket;

public class Proxy implements Subscribable
{
    private final String host;
    private final int port;

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
