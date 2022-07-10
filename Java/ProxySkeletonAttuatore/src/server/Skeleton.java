package server;

import dispatcher.*;

import java.io.*;
import java.net.*;

public class Skeleton extends Thread
{
    private Socket socket;
    private Dispatchable dispatcher;

    public Skeleton(Socket socket, Dispatchable dispatcher)
    {
        this.socket=socket;
        this.dispatcher = dispatcher;
    }


    public void run()
    {
        System.out.println ("[SrvThread] run thread! " );
        try{
            DataInputStream dataIn = new DataInputStream(socket.getInputStream());
            DataOutputStream dataOut = new DataOutputStream(socket.getOutputStream());

            String method = dataIn.readUTF();
            int x;

            if(method.compareTo("sendCmd") == 0){
                x=dataIn.readInt();
                System.out.println ("	[SrvThread] method: " + method + ", " + x);

                dispatcher.sendCmd(x);

                dataOut.writeUTF("ack");
            }
            else if(method.compareTo("getCmd") == 0){
                System.out.println ("	[SrvThread] method: " + method + ", -");
                x = dispatcher.getCmd();

                dataOut.writeInt ( x);
            }
            else
                System.out.println ("Error: unknown method!");

            System.out.println ();
            socket.close();
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}
