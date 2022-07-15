package server;

import interfaces.Logger;
import jdk.jfr.Frequency;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.nio.charset.StandardCharsets;
import java.util.StringTokenizer;

public class Worker extends Thread
{
    private DatagramSocket socket;
    private DatagramPacket packet;
    private Logger logger;

    public Worker(DatagramSocket socket, DatagramPacket packet, Logger logger)
    {
        this.socket = socket;
        this.packet = packet;
        this.logger = logger;
    }

    public void run()
    {
        String message = new String(packet.getData(), 0, packet.getLength());

        System.out.println ( "\n[Worker] Processing packet:\n" +
                "-> request size = " + packet.getLength() + "\n"
                + "-> message = " + message );

        StringTokenizer tokens = new StringTokenizer(message, "+");
        String method = tokens.nextToken();

        if(method.equals("storeData")){
            int data = Integer.parseInt(tokens.nextToken());

            logger.storeData(data);

            String replyMessage = "ack";
            DatagramPacket reply = new DatagramPacket(
                    replyMessage.getBytes(), replyMessage.getBytes().length, packet.getAddress(), packet.getPort());

            try{
                socket.send(reply);
            }
            catch(IOException e){
                throw new RuntimeException(e);
            }
        }
    }
}
