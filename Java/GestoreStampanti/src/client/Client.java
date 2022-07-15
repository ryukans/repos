package client;

import interfaces.dispatcher.IDispatcher;

import java.rmi.RemoteException;
import java.util.Random;

public class Client extends Thread
{
    private IDispatcher dispatcher;

    public Client(IDispatcher dispatcher){
        this.dispatcher = dispatcher;
    }

    public void run()
    {
        for(int i = 0; i < 3; i++){
            String docName = "doc" + new Random().nextInt(1, 50);
            try {
                dispatcher.printRequest(docName);
            } catch (RemoteException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
