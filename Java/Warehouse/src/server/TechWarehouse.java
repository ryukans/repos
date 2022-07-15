package server;

import interfaces.Warehouse;
import queue.*;
import queueImp.*;

public class TechWarehouse extends ServerSkeleton
{
    private Queue laptops;
    private Queue smartphones;

    public TechWarehouse(int port)
    {
        super(port);
        laptops = new CircularQueueMutex(new CircularQueue(5));
        smartphones = new CircularQueueMutex(new CircularQueue(5));
    }

    @Override
    public void deposit(String item, int id)
    {
        switch(item.toLowerCase()){
            case "laptop" -> laptops.push(id);
            case "smartphone" -> smartphones.push(id);
        }
        System.out.printf("Item <%s, %d> has been deposited on warehouse\n", item, id);
    }

    @Override
    public int withdraw(String item)
    {
        int id = 0;

        switch(item.toLowerCase()){
            case "laptop" -> id = laptops.pop();
            case "smartphone" -> id = smartphones.pop();
        }
        System.out.printf("Item <%s, %d> has been withdrawn from warehouse\n", item, id);

        return id;
    }
}
