package client;

import interfaces.Dispatchable;

import java.rmi.RemoteException;
import java.util.Random;

public class Node extends Thread
{
    private Dispatchable dispatcher;
    public Node(Dispatchable dispatcher)
    {
        this.dispatcher = dispatcher;
    }

    @Override
    public void run()
    {
        try {
            for (int i = 0; i < 3; i++){
                int t = new Random().nextInt(1, 3);
                Thread.sleep(t* 1000L);

                String docName = "doc" + new Random().nextInt(1, 50);
                dispatcher.printRequest(docName);
            }
        }
        catch(RemoteException | InterruptedException e){
            e.printStackTrace();
        }
    }
}
