package server;

import java.util.Vector;

public class Dispatcher extends DispatcherSkeleton
{
    private Vector<Integer> commands;
    private int count;
    private int head;
    private int tail;
    private static final int MAXSIZE = 5;
    public Dispatcher(int port)
    {
        super(port);
        commands = new Vector<>(MAXSIZE);
        count = head = tail = 0;
    }
    @Override
    public synchronized void sendCmd(int command)
    {
        System.out.println("adding to queue");
        while(count == MAXSIZE){
            try {
                wait();
                System.out.println("Buffer is full");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }

        commands.add(tail, command);
        tail = (tail+1)%MAXSIZE;
        count++;
        System.out.println("Command " + command + " added");
        notifyAll();
    }

    @Override
    public synchronized int getCmd()
    {
        int command;

        while(count == 0){
            try {
                wait();
                System.out.println("Buffer is empty");
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        command = commands.get(head);
        head = (head+1)%MAXSIZE;
        count--;
        System.out.println("Command " + command + " read");

        notifyAll();

        return command;
    }
}
