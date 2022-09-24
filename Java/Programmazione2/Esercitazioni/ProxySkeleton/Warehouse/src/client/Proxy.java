package client;

import interfaces.Warehouse;

import java.io.*;
import java.net.Socket;

public class Proxy implements Warehouse
{
    private String host;
    private int port;

    public Proxy(String host, int port)
    {
        this.host = host;
        this.port = port;
    }

    @Override
    public void deposit(String item, int id)
    {
        try {
            Socket socket = new Socket(host, port);

            DataOutputStream out = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );

            //out.writeUTF(Operation.DEPOSIT);
            out.writeUTF("deposit");
            out.writeUTF(item);
            out.writeInt(id);
            out.flush();

            out.close();
            socket.close();
        }
        catch(IOException e){
            throw new RuntimeException(e);
        }
    }

    @Override
    public int withdraw(String item)
    {
        int id;
        try{
            Socket socket = new Socket(host, port);
            DataOutputStream out = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );
            DataInputStream in = new DataInputStream(
                    new BufferedInputStream(socket.getInputStream())
            );

            out.writeUTF("withdraw");
            out.writeUTF(item);
            out.flush();
            id = in.readInt();

            socket.close();
            in.close();
            out.close();

            return id;
        }
        catch(IOException e){
            e.printStackTrace();
        }

        return 0;
    }
}
