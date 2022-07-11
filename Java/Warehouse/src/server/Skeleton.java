package server;

import interfaces.Warehouse;

import java.io.*;
import java.net.Socket;

public class Skeleton extends Thread
{
    private Socket socket;
    private Warehouse warehouse;

    public Skeleton(Socket socket, Warehouse warehouse)
    {
        this.socket = socket;
        this.warehouse = warehouse;
    }

    public void run()
    {
        try {
            DataOutputStream out = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );
            DataInputStream in = new DataInputStream(
                    new BufferedInputStream(socket.getInputStream())
            );

            String op = in.readUTF();
            String item = in.readUTF();
            int id = in.readInt();

            switch(op.toLowerCase()){
                case "deposit" -> {
                    //System.out.println("");
                    warehouse.deposit(item, id);
                }
                case "withdraw" -> {
                    warehouse.withdraw(item);
                }
            }

            out.close();
            in.close();
        }
        catch(IOException e){
            throw new RuntimeException(e);
        }

    }
}
