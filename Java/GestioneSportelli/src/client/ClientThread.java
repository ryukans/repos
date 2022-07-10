package client;

import interfaces.IGestoreSportello;

import java.rmi.RemoteException;
import java.util.Random;

public class ClientThread extends Thread
{
    private int idClient;
    private int requests;
    private IGestoreSportello gestore;

    public ClientThread(int requests, IGestoreSportello gestore)
    {
        this.requests = requests;
        this.gestore = gestore;
    }

    public void run()
    {
        for(int i = 0; i < this.requests; i++){
            try{
                int t = new Random().nextInt(1, 3);
                Thread.sleep(t* 1000L);

                this.idClient = new Random().nextInt(1, 100);
                gestore.sottoponiRichiesta(this.idClient);
            }
            catch(InterruptedException | RemoteException e){
                e.printStackTrace();
            }
        }
    }
}
