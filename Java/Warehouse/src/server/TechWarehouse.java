package server;

import interfaces.Warehouse;
import queue.*;
import queueImp.*;

public class TechWarehouse implements Warehouse
{
    private Queue laptops;
    private Queue smartphones;

    public TechWarehouse()
    {
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
    }

    @Override
    public int withdraw(String item)
    {
        int id = 0;

        switch(item.toLowerCase()){
            case "laptop" -> id = laptops.pop();
            case "smartphone" -> id = smartphones.pop();
        }

        return id;
    }
}
