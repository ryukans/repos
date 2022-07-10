package client;

import dispatcher.Dispatchable;

public class ClientMain
{
    public static void main(String[] args)
    {
        Dispatchable dispatcher = new DispatcherProxy("172.0.0.1", 8000);
        Client[] tClients = new Client[5];
        /*
        for(int i = 0; i < 5; i++){
            String name = "Client " + (i+1);
            tClients[i] = new Client(name, dispatcher);
            tClients[i].start();
        }*/
        //new Client("Client 1", dispatcher).start();

        int x = (int)(Math.random()*4);

        System.out.println ("[CLN] invio comando # " + x );

        dispatcher.sendCmd(x);

    }
}
