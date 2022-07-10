package server;

import interfaces.IGestoreSportello;
import interfaces.ISportello;

import java.io.*;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Random;
import java.util.concurrent.Semaphore;

public class Sportello
        extends UnicastRemoteObject
        implements ISportello
{
    private File clienti;
    private Semaphore maxReqs;
    private Semaphore maxConcurrentReqs;

    protected Sportello() throws RemoteException
    {
        clienti = new File("./");
        maxReqs = new Semaphore(5);
        maxConcurrentReqs = new Semaphore(3);
    }


    @Override
    public boolean serviRichiesta(int idClient) throws RemoteException
    {
        if(!maxReqs.tryAcquire())
            return false;

        int t = new Random().nextInt(1, 5);

        try {
            maxConcurrentReqs.acquire();

            Thread.sleep(t* 1000L);
            DataOutputStream outStream = new DataOutputStream(
                    new FileOutputStream(clienti)
            );

            outStream.writeInt(idClient);
            outStream.flush();
            outStream.close();

            System.out.println("[Sportello] Servita richiesta da " + idClient);
        }
        catch(InterruptedException e){
            e.printStackTrace();
            return false;
        }
        catch(IOException e){
            e.printStackTrace();
            return false;
        }
        finally{
            maxConcurrentReqs.release();
            maxReqs.release();
        }
        return true;
    }
}
