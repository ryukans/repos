package server;

import interfaces.Dispatchable;

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
        try{
            DataOutputStream out = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );
            DataInputStream in = new DataInputStream(
                    new BufferedInputStream(socket.getInputStream())
            );

            String op = in.readUTF();
            System.out.println("[Debug] - operation invoked: " + op);

            switch(op.toLowerCase()){
               // case "add" -> dispatcher.addPrinter();
                case "print" -> dispatcher.printRequest(docName);
            }
        }
        catch(IOException e){
            e.printStackTrace();
        }

    }
}
