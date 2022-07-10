package client;

import interfaces.Dispatchable;
import server.Dispatcher;

import java.rmi.RemoteException;

public class Test
{
    public static void main(String[] args) throws RemoteException {
        Dispatchable dispatcher = new Dispatcher();
        Node[] tNodes = new Node[5];

        for(int i = 0; i < 5; i++) {
            tNodes[i] = new Node(dispatcher);
            tNodes[i].start();
        }


    }
}
