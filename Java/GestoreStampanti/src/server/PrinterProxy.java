package server;

import interfaces.printer.IPrinter;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class PrinterProxy implements IPrinter
{
    private String host;
    private int port;

    public PrinterProxy(String host, int port)
    {
        this.host = host;
        this.port = port;
    }

    @Override
    public boolean print(String docName)
    {
        try {
            Socket socket = new Socket(this.host, this.port);
            DataOutputStream out = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );

            out.writeUTF("print");
            out.writeUTF(docName);
            out.flush();


            out.close();
            socket.close();

            return true;
        }
        catch(IOException e){
            e.printStackTrace();
        }
        return false;
    }
}
