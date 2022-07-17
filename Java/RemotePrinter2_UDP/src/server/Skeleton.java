package server;

import printer.Printer;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.Socket;

public class Skeleton extends Thread
{
    private final Runnable target;
    private final Printer printer;
    private  Socket socket;

    private  DatagramSocket datagramSocket;
    private  DatagramPacket packet;

    public Skeleton(Runnable target, Printer printer, Socket socket)
    {
        this.target = target;
        this.printer = printer;
        this.socket = socket;
    }

    public Skeleton(Runnable target, Printer printer, DatagramSocket datagramSocket, DatagramPacket packet)
    {
        this.target =  target;
        this.printer = printer;
        this.datagramSocket =  datagramSocket;
        this.packet = packet;
    }

    @Override
    public void run() {
        target.run();
    }
}