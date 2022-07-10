package client;

import dispatcher.Dispatchable;

import java.io.*;
import java.net.Socket;
import java.net.UnknownHostException;

public class DispatcherProxy implements Dispatchable
{
    private String host;
    private int port;

    public DispatcherProxy(String host, int port)
    {
        this.host = host;
        this.port = port;
    }

    @Override
    public void sendCmd(int command)
    {
        try(Socket socket = new Socket(this.host, this.port)){
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            DataInputStream in = new DataInputStream(socket.getInputStream());

            out.writeUTF("sendCmd");
            out.writeInt(command);
            in.readUTF();

        }
        catch(IOException e){
            System.out.println(e.toString());
            throw new RuntimeException(e);
        }
    }

    @Override
    public int getCmd()
    {
        int command = 0;
        try{
            Socket socket = new Socket(host, port);
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            DataInputStream in = new DataInputStream(socket.getInputStream());

            out.writeUTF("getCmd");
            command = in.readInt();

            socket.close();
        }
        catch (UnknownHostException e){
            System.out.println(e.toString());
            throw new RuntimeException(e);
        }
        catch (IOException e){
            System.out.println(e.toString());
            throw new RuntimeException(e);
        }
        return command;
    }
}
