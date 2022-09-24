package client;

import dispatcher.ObserverDispatcher;
import dispatcher.Reading;
import interfaces.Dispatcher;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.Random;

public class Generator
{
    public static void main(String[] args)
    {
        try{
            Registry rmi = LocateRegistry.getRegistry();
            Dispatcher dispatcher = (Dispatcher) rmi.lookup(ObserverDispatcher.CLASSNAME);
            //Observable observer = new Observer(dispatcher);

            for(int i = 0; i < 3; i++){
                /*
                * Creating generator thread
                * */
                new Thread(()->{
                    try{
                        Reading reading = new Reading();
                        String type;
                        int value;

                        type = (Math.random() < 0.5) ? "pressure" : "temperature";
                        value = new Random().nextInt(50);
                        reading.setType(type);
                        reading.setValue(value);
                        dispatcher.setReading(reading);

                        System.out.printf("Generator | former reading set <%s, %d>\n", type, value);

                        Thread.sleep(5000L);

                        type = (Math.random() < 0.5) ? "pressure" : "temperature";
                        value = new Random().nextInt(50);
                        reading.setType(type);
                        reading.setValue(value);
                        dispatcher.setReading(reading);

                        System.out.printf("Generator | latter reading set <%s, %d>\n", type, value);
                    }
                    catch(InterruptedException | RemoteException e){
                        throw new RuntimeException(e);
                    }
                }).start();
            }
        }
        catch(RemoteException | NotBoundException e){
            throw new RuntimeException(e);
        }
    }
}
