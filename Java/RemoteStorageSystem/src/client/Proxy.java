package client;

import interfaces.Logger;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

public class Proxy implements Logger
{
    private DatagramSocket socket;
    private int port;

    public Proxy(int port)
    {
        try{
            socket = new DatagramSocket();
        }
        catch(SocketException e){
            throw new RuntimeException(e);
        }

        this.port = port;
    }
    @Override
    public void storeData(int data)
    {
        String message = "storeData+" + data;

        try{
            DatagramPacket request =
                    new DatagramPacket(message.getBytes(), message.getBytes().length, InetAddress.getLocalHost(), this.port);

            socket.send(request);

            /*
            * In order to receive ack message
            * */
            byte[] buffer = new byte[100];
            DatagramPacket reply = new DatagramPacket(buffer, buffer.length);

            socket.receive(reply);
        }
        catch(IOException e){
            e.printStackTrace();
        }
    }
}
