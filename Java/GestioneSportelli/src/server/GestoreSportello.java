package server;

import interfaces.IGestoreSportello;
import interfaces.ISportello;

import java.io.Serial;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.Vector;


public class GestoreSportello
        extends UnicastRemoteObject
        implements IGestoreSportello
{
    @Serial
    private static final long serialVersionUID = -3549284255644804843L;
    private Vector<ISportello> sportelli;

    protected GestoreSportello() throws RemoteException{
        sportelli = new Vector<>();
    }

    @Override
    public void sottoponiRichiesta(int idClient) throws RemoteException
    {
        int i = 0;
        boolean servita = false;
        while(i < this.sportelli.size() && !servita)
            servita = this.sportelli.get(i++).serviRichiesta(idClient);

    }

    @Override
    public void sottoscrivi(ISportello sportello) throws RemoteException {
        sportelli.add(sportello);
    }
}