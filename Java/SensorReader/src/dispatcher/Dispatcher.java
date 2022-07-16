package dispatcher;

import client.Observer;
import interfaces.Dispatchable;
import interfaces.Observable;
import interfaces.Readable;

import java.io.Serial;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

import java.rmi.RemoteException;
import java.util.concurrent.Semaphore;

public class Dispatcher
        extends UnicastRemoteObject
        implements Dispatchable
{
    @Serial
    private static final long serialVersionUID = 6722737788425221179L;
    public static final String CLASSNAME = "DISPATCHER";
    private Readable status;
    Hashtable<String, Observable> observers;
    private Semaphore mutex;

    public Dispatcher() throws RemoteException
    {
        observers = new Hashtable<>();
        mutex = new Semaphore(1);
    }

    @Override
    public synchronized void setReading(Readable reading) throws RemoteException
    {
        System.out.println("Set Reading");

        try{
            mutex.acquire();
        }
        catch(InterruptedException e){
            throw new RuntimeException(e);
        }

        this.status = reading;

        for(Map.Entry<String, Observable> observer : this.observers.entrySet()){
            if(status.getType().equalsIgnoreCase(observer.getKey())){
                observer.getValue().notifyReading();
            }
        }

        int t = new Random().nextInt(1, 5);

        try{
            Thread.sleep(t*1000L);
        }
        catch(InterruptedException e){
            throw new RuntimeException(e);
        }

        mutex.release();
    }

    @Override
    public Readable getReading() throws RemoteException{
        return status;
    }

    @Override
    public void attach(Observable observer, String type) throws RemoteException
    {
        this.observers.put(type, (Observable)observer);
        System.out.println("Dispatcher | Observer attached");
        System.out.println("Observers:");

        for(HashMap.Entry<String, Observable> ob : observers.entrySet()){
            System.out.println("Observer: " + ob.getValue().toString() + "value: " + ob.getKey());
        }

    }
}
