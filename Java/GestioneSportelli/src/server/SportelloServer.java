package server;

import interfaces.IGestoreSportello;
import interfaces.ISportello;

import java.rmi.AccessException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class SportelloServer
{
    public static void main(String[] args)
    {
        try{
            IGestoreSportello gestore = (IGestoreSportello) LocateRegistry.getRegistry().lookup("gestore");
            ISportello sportello = new Sportello();

            /*
            * Lo Sportello, al proprio avvio, si sottoscrive al Gestore.
            * */
            gestore.sottoscrivi(sportello);
        }
        catch(RemoteException | NotBoundException e) {
            e.printStackTrace();
        }
    }
}
