package dispatcher;

import interfaces.Observable;
import interfaces.Readable;

import java.io.Serial;
import java.rmi.server.UnicastRemoteObject;
import java.util.*;

import java.rmi.RemoteException;
import java.util.concurrent.Semaphore;

public class ObserverDispatcher
        extends UnicastRemoteObject
        implements interfaces.Dispatcher
{
    @Serial
    private static final long serialVersionUID = 6722737788425221179L;
    public static final String CLASSNAME = "DISPATCHER";
    private Readable status;

    /*
    * Key: status, i.e. String object
    * Value: Observer object
    * */
    private final Hashtable<String, Observable> observers;
    private final Semaphore mutex;

    public ObserverDispatcher() throws RemoteException
    {
        observers = new Hashtable<>();
        mutex = new Semaphore(1);
    }

    @Override
    public synchronized void setReading(Readable reading) throws RemoteException
    {
        /*
        * Debug print
        * */
        //System.out.println("Set Reading");

        try{
            mutex.acquire();
        }
        catch(InterruptedException e){
            throw new RuntimeException(e);
        }

        this.status = reading;

        for(Map.Entry<String, Observable> observer : this.observers.entrySet()){
            String key = observer.getKey(); //get observer associated status.
            if(status.getType().equalsIgnoreCase(key)){
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
        this.observers.put(type, (Observable)observer); //redundant casting to Observable type
        System.out.println("ObserverDispatcher | Observer attached");
        System.out.println("Observers:");

        for(HashMap.Entry<String, Observable> ob : observers.entrySet()){
            System.out.println("Observer: " + ob.getValue().toString() + "value: " + ob.getKey());
        }

    }
}
