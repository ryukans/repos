package printer;

import interfaces.printer.IPrinter;

import java.io.*;
import java.net.Socket;

public class Skeleton extends Thread
{
    private Socket socket;
    private IPrinter printer;

    public Skeleton(Socket socket, IPrinter printer)
    {
        this.socket = socket;
        this.printer = printer;
    }

    public void run()
    {
        try{
            DataInputStream in = new DataInputStream(
                    new BufferedInputStream(socket.getInputStream())
            );

            String op = in.readUTF();
            String docName = in.readUTF();

            if(op.equalsIgnoreCase("print"))
                printer.print(docName);
            else
                System.out.printf("Operation <%s> is not valid\n", op);

            in.close();
        }
        catch(IOException e){
            throw new RuntimeException(e);
        }
    }
}
