package dispatcher;

import printer.Printer;

import java.io.Serial;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.util.Locale;
import java.util.Vector;

public class PrinterDispatcher
        extends UnicastRemoteObject
        implements Dispatcher
{
    @Serial
    private static final long serialVersionUID = -8183055865982053460L;
    private final Vector<Printer> printers;
    public static final String CLASSNAME = "PrinterDispatcher";

    public PrinterDispatcher() throws RemoteException {
        printers = new Vector<>();
    }

    @Override
    public void addPrinter(String host, int port) throws RemoteException {
        printers.add(new PrinterProxy(host, port));
    }

    @Override
    public boolean printRequest(String docName) throws RemoteException
    {
        boolean found = false;
        int i = 0;

        while(i < printers.size() && !found)
            found = printers.get(i++).print(docName); // calls print() with proxy object

        return found;
    }

    public static void main(String[] args)
    {
        try {
            Registry rmi = LocateRegistry.getRegistry();
            Dispatcher dispatcher = new PrinterDispatcher();

            rmi.rebind(PrinterDispatcher.CLASSNAME, dispatcher);

            System.out.println("Dispatcher | Online");
        }
        catch(RemoteException e) {
            throw new RuntimeException(e);
        }
    }
}
