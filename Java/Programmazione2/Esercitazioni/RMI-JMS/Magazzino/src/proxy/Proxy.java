package proxy;

import interfaccia.IService;

import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Proxy
{
    public static void main(String[] args)
    {
        Registry rmi = null;
        try {
            rmi = LocateRegistry.getRegistry();
            IService service = (IService) rmi.lookup("servizio");

            Thread receiver = new Thread(new Receiver(service));
            receiver.start();

            System.out.println("[Proxy] - Avviato receiver");

        } catch (RemoteException | NotBoundException e) {
            throw new RuntimeException(e);
        }
    }
}
