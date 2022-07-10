package server;

import service.ICounter;

import java.io.*;
import java.net.Socket;

public class SkeletonThread extends Thread
{
    private Socket socket;
    private ICounter counter;

    public SkeletonThread(Socket socket, ICounter counter)
    {
        this.socket = socket;
        this.counter = counter;
    }

    public void run()
    {
        try{
            DataOutputStream outputStream = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );
            DataInputStream inputStream = new DataInputStream(
                    new BufferedInputStream(socket.getInputStream())
            );

            String op = inputStream.readUTF();
            System.out.println("Operation: " + op);

            switch(op.toLowerCase()){
                case "inc" -> counter.inc();
                case "sum" -> {
                    int value = inputStream.readInt();
                    counter.sum(value);
                }
                case "sqr" -> counter.square();
                case "get" -> {
                    outputStream.writeInt(counter.get());
                    outputStream.flush();
                }
            }
        }
        catch(IOException e){
            e.printStackTrace();
        }

    }
}
