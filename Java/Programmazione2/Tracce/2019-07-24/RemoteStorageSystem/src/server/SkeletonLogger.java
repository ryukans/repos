package server;

import interfaces.Logger;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class SkeletonLogger implements Logger
{
    private final Logger logger;
    private final int port;

    public SkeletonLogger(Logger logger, int port)
    {
        this.logger = logger;
        this.port = port;
    }

    public void runSkeleton()
    {
        try{
            DatagramSocket socket = new DatagramSocket(this.port);

            //System.out.println("Skeleton entering while loop"); Debug only

            while(true){
                byte[] buffer = new byte[100];
                DatagramPacket request = new DatagramPacket(buffer, buffer.length);

                socket.receive(request);

                Worker worker = new Worker(socket, request,this);

                worker.start();
            }
        }
        catch(IOException e){
            throw new RuntimeException(e);
        }

    }

    @Override
    public void storeData(int data){
        logger.storeData(data);
    }
}
