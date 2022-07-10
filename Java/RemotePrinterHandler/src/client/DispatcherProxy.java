package client;

import interfaces.Dispatchable;
import interfaces.Printer;
import server.Dispatcher;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.rmi.RemoteException;
import java.rmi.UnknownHostException;

public abstract class DispatcherProxy implements Dispatchable
{
    private String host;
    private int port;

    public DispatcherProxy(String host, int port)
    {
        this.host = host;
        this.port = port;
    }

    @Override
    public boolean printRequest(String docName) throws RemoteException
    {
        try(Socket socket = new Socket(this.host, this.port)){
            DataOutputStream out = new DataOutputStream(
                    new BufferedOutputStream(socket.getOutputStream())
            );

            out.writeUTF("print");
            out.flush();
        }
        catch(UnknownHostException e){
            e.printStackTrace();
            return false;
        }
        catch(IOException e){
            e.printStackTrace();
            return false;
        }
        return true;
    }
}
