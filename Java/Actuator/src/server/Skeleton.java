package server;

import dispatcher.Dispatchable;

import java.io.*;
import java.net.Socket;

public class Skeleton extends Thread
{
    private Socket socket;
    private Dispatchable dispatcher;

    public Skeleton(Socket socket, Dispatchable dispatcher)
    {
        this.socket = socket;
        this.dispatcher = dispatcher;
    }

    public void run()
    {
        System.out.println ("[Skeleton thread] run thread! " );

        try {
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());
            DataInputStream in = new DataInputStream(socket.getInputStream());

            String op = in.readUTF();
            System.out.println("Operation: " + op);

            switch(op.toLowerCase()){
                case "sendcmd" -> {
                    int command = in.readInt();
                    dispatcher.sendCmd(command);
                    out.writeUTF("ack");
                }
                case "getcmd" -> {
                    int command = dispatcher.getCmd();
                    out.writeInt(command);
                }
            }
            socket.close();
        }
        catch(IOException e){
            throw new RuntimeException(e);
        }
    }
}
