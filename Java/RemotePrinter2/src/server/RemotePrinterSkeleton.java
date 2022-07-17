package server;

import printer.Printer;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class RemotePrinterSkeleton implements Printer
{
    private final Printer printer;
    private final int port;

    public RemotePrinterSkeleton(Printer printer, int port)
    {
        this.printer = printer;
        this.port = port;
    }

    public void runSkeleton()
    {
        try(ServerSocket serverSocket = new ServerSocket(this.port)) {
            while(true) {
                final Socket socket = serverSocket.accept();
                final Printer ref = this;

                new Skeleton(() -> {
                    try {
                        DataInputStream in = new DataInputStream(socket.getInputStream());
                        String method = in.readUTF();

                        if(method.equals("print")) {
                            String docName = in.readUTF();
                            ref.print(docName);
                        }

                        in.close();
                    }
                    catch(IOException e) {
                        throw new RuntimeException(e);
                    }
                }, ref, socket).start();
            }
        }
        catch(IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public boolean print(String docName) {
        return printer.print(docName);
    }
}
