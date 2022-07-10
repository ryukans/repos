package server;


import java.util.Vector;

public class Dispatcher extends DispatcherSkeleton
{
    private int command;

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

    public synchronized void sendCmd(int command)
    {
        while(count == MAXSIZE){
            try {
                System.out.println("Buffer is full");
                wait();
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
        System.out.println("get command");
        int command;

        while(count == 0){
            try {
                System.out.println("Buffer is empty");
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }

        command = commands.get(head);
        //commands.remove(head);
        head = (head+1)%MAXSIZE;
        count--;
        System.out.println("Command " + command + " read");

        notifyAll();

        return command;
    }
}
