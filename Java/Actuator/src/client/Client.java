package client;

import dispatcher.Dispatchable;

import java.util.Random;

public class Client extends Thread
{
    private String name;
    private Dispatchable dispatcher;
    public Client(String name, Dispatchable dispatcher)
    {
        this.name = name;
        this.dispatcher = dispatcher;
    }

    public void run()
    {
        for(int i = 0; i < 3; i++){
            int t = new Random().nextInt(2, 4);
            int command = new Random().nextInt(0, 3);
            System.out.println("[" + name + "] - req: " + i + " cmd: " + command);
            dispatcher.sendCmd(command);
            try {
                Thread.sleep(t*1000L);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
