package interfaces;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface IGestoreSportello extends Remote
{
    public void sottoponiRichiesta(int idClient) throws RemoteException;
    public void sottoscrivi(ISportello sportello) throws RemoteException;
}
