package client;

import service.ICounter;

import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Objects;

public class CounterProxy implements ICounter
{
    private String host;
    private int port;

    public CounterProxy(String host, int port)
    {
        this.host = host;
        this.port = port;
    }

    @Override
    public void inc()
    {
        try{
            Socket socket = new Socket(this.host, this.port);
            DataOutputStream outStream = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );

            outStream.writeUTF("inc");
            outStream.flush();

            socket.close();
        }
        catch(UnknownHostException e){
            e.printStackTrace();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }

    @Override
    public void sum(int value)
    {
        try{
            Socket socket = new Socket(this.host, this.port);
            DataOutputStream outStream = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );

            outStream.writeUTF("sum");
            outStream.writeInt(value);
            outStream.flush();

            socket.close();
        }
        catch(UnknownHostException e){
            e.printStackTrace();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }

    @Override
    public int get()
    {
        //Socket socket = null;
        try(Socket socket = new Socket(this.host, this.port))
        {
            DataOutputStream outStream = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );
            DataInputStream inStream = new DataInputStream(
                    new BufferedInputStream(socket.getInputStream())
            );

            outStream.writeUTF("get");
            outStream.flush();
            int x = inStream.readInt();

            socket.close();

            return x;
        }
        catch(UnknownHostException e){
            e.printStackTrace();
        }
        catch(IOException e){
            e.printStackTrace();
        }

        return 0;
    }

    @Override
    public void square()
    {
        try{
            Socket socket = new Socket(this.host, this.port);
            DataOutputStream outStream = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );

            outStream.writeUTF("sqr");
            outStream.flush();

            socket.close();
        }
        catch(UnknownHostException e){
            e.printStackTrace();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}
