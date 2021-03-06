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
                case "deposit" -> warehouse.deposit(item, id);
                case "withdraw" -> System.out.println("Item id: " + warehouse.withdraw(item));
                default -> System.out.println("Operation <"+ op + "> is not valid");
            }

            out.close();
            in.close();
        }
        catch(IOException e){
            throw new RuntimeException(e);
        }

    }
}
