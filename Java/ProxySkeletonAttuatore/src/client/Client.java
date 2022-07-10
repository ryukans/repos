package client;

import dispatcher.*;

public class Client
{
    public static void main(String[] args)
    {
        Dispatchable dispatcher = new DispatcherProxy("127.0.0.1", 8000);

        int x = (int)(Math.random()*4);

        System.out.println ("[Client] - sending command: " + x );
        dispatcher.sendCmd(x);
    }
}
