package server;

import dispatcher.Dispatchable;

public class DispatcherServer
{
    public static void main(String[] args)
    {
        Dispatcher dispatcher = new Dispatcher(8000);

        dispatcher.runSkeleton();
    }
}
