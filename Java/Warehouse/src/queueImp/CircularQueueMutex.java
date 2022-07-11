package queueImp;

import queue.Queue;
import queue.QueueWrapper;

import javax.swing.*;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class CircularQueueMutex extends QueueWrapper
{
    private Lock mutex;
    private Condition empty;
    private Condition full;

    public CircularQueueMutex(Queue queue)
    {
        super(queue);
        mutex = new ReentrantLock();
        empty = mutex.newCondition();
        full = mutex.newCondition();

    }

    @Override
    public void push(int element)
    {
        mutex.lock();

        try{
           while(super.queue.isFull()){
               System.out.println("Queue is full; on wait");
               try{
                   empty.await();
               }
               catch(InterruptedException e){
                   throw new RuntimeException(e);
               }
           }
           super.queue.push(element);
           full.signal();
        }
        finally{
            mutex.unlock();
        }
    }

    @Override
    public int pop()
    {
        int element;

        mutex.lock();

        try{
           while(super.queue.isEmpty()){
               System.out.println("Queue is empty; on wait");
               try {
                   full.await();
               }
               catch(InterruptedException e){
                   throw new RuntimeException(e);
               }
           }
           element = super.queue.pop();
           empty.signal();
        }
        finally{
            mutex.unlock();
        }
        return element;
    }
}
