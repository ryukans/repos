package dispatcher;

import printer.Printer;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;

public class PrinterProxy implements Printer
{
    private final String host;
    private final int port;

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
            DataOutputStream out = new DataOutputStream(socket.getOutputStream());

            out.writeUTF("print");
            out.writeUTF(docName);
            out.flush();
            out.close();

            return true;
        }
        catch(IOException e) {
            throw new RuntimeException(e);
        }
    }
}
