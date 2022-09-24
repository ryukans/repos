package server;

import printer.Printer;

import java.io.IOException;
import java.net.*;
import java.util.StringTokenizer;

public class RemotePrinterSkeleton implements Printer
{
    private final Printer printer;
    private final int port;

    public RemotePrinterSkeleton(Printer printer, int port)
    {
        this.printer = printer;
        this.port = port;
    }

    public void runSkeletonUDP()
    {
        try(DatagramSocket serverSocket = new DatagramSocket(this.port)) {
            while(true) {
                byte[] buffer = new byte[Printer.BUFFER_SIZE];
                DatagramPacket request = new DatagramPacket(buffer, buffer.length);

                serverSocket.receive(request);

                final Printer ref = this;
                new Skeleton(() -> {
                    String message = new String(request.getData(), 0, request.getLength());
                    StringTokenizer tokens = new StringTokenizer(message, Printer.MESSAGE_TOKEN);
                    String method = tokens.nextToken();

                    if(method.equals(methods.print.toString())) {
                        String docName = tokens.nextToken();
                        ref.print(docName);

                        String reply = Printer.ACKNOWNLEDGE_MESSAGE;
                        DatagramPacket packet = new DatagramPacket(
                                reply.getBytes(), reply.getBytes().length, request.getAddress(), request.getPort());

                        try {
                            serverSocket.send(packet);
                        }
                        catch(IOException e) {
                            throw new RuntimeException(e);
                        }
                    }
                    /*
                    * Errore: se si chiude la connessione del socket gli altri thread durante la loro esecuzione
                    * solleveranno un eccezione dovuta alla connessione ormai chiusa.
                    *
                    * Error: closing socket connection here will lead other threads in execution to rise an
                    * exception due the connection already been closed.
                    * */
                    //serverSocket.close();
                }, ref, serverSocket, request).start();

            }
        } catch(IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public boolean print(String docName) {
        return printer.print(docName);
    }
}
