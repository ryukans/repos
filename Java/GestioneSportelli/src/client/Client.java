package client;

import interfaces.IGestoreSportello;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Client
{
    public static void main(String[] args)
    {
        final int NUM_THREADS = 10;
        final int NUM_REQUESTS = 10;

        ClientThread[] tClients = new ClientThread[NUM_THREADS];
        try{
            //Registry rmi = LocateRegistry.getRegistry();
            IGestoreSportello gestore = (IGestoreSportello)LocateRegistry.getRegistry().lookup("gestore");

            for(int i = 0; i < NUM_THREADS; i++){
                tClients[i] = new ClientThread(NUM_REQUESTS, gestore);
                tClients[i].start();
            }
        }
        catch(RemoteException | NotBoundException e){
            e.printStackTrace();
        }
    }
}
