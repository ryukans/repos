package dispatcher;


import printer.Printer;

import javax.jms.JMSException;
import javax.jms.MapMessage;
import javax.jms.Message;
import javax.jms.MessageListener;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;

public class DispatcherListener implements MessageListener
{
    @Override
    public void onMessage(Message args)
    {
        MapMessage message = (MapMessage)args;

        Thread t = new Thread(() -> {
            try {
                String docName = message.getString("docName");
                String printerName = message.getString("printerName");
                Printer remotePrinter = (Printer) LocateRegistry.getRegistry().lookup(printerName);

                System.out.println("Thread | Document name: " + docName);
                remotePrinter.printDoc(docName);
            }
            catch(RemoteException | NotBoundException | JMSException e) {
                throw new RuntimeException(e);
            }
        });

        t.start();
    }
}
