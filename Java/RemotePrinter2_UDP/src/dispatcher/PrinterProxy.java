package dispatcher;

import printer.Printer;

import java.io.IOException;
import java.net.*;

public class PrinterProxy implements Printer
{
    private final InetSocketAddress inet;
    public PrinterProxy(String host, int port) {
        inet = new InetSocketAddress(host, port);
    }

    public boolean print(String docName)
    {
        try (DatagramSocket socket = new DatagramSocket()){

            String message = Printer.methods.print + Printer.MESSAGE_TOKEN + docName;
            DatagramPacket request = new DatagramPacket(
                    message.getBytes(), message.getBytes().length, inet.getAddress(), inet.getPort());

            socket.send(request);

            byte[] buffer = new byte[Printer.BUFFER_SIZE];
            DatagramPacket ackReply = new DatagramPacket(buffer, buffer.length);

            socket.receive(ackReply);
        }
        catch(IOException e) {
            throw new RuntimeException(e);
        }

        return true;
    }
}
