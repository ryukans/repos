package server;

import printer.Printer;

import java.net.Socket;

public class Skeleton extends Thread
{
    private final Runnable target;
    private final Printer printer;
    private final Socket socket;

    public Skeleton(Runnable target, Printer printer, Socket socket)
    {
        this.target = target;
        this.printer = printer;
        this.socket = socket;
    }

    @Override
    public void run() {
        target.run();
    }
}
