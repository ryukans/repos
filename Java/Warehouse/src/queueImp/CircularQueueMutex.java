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
    private Condition producer;
    private Condition consumer;

    public CircularQueueMutex(Queue queue)
    {
        super(queue);
        mutex = new ReentrantLock();
        producer = mutex.newCondition();
        consumer = mutex.newCondition();

    }

    @Override
    public void push(int element)
    {
        mutex.lock();

        try{
           while(queue.isFull()){
               System.out.println("Queue is full; on wait");
               producer.await();
           }
           queue.push(element);
           consumer.signal();
        }
        catch(InterruptedException e){
            throw new RuntimeException(e);
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
           while(queue.isEmpty()){
               System.out.println("Queue is empty; on wait");
               consumer.await();
           }
           element = queue.pop();
           producer.signal();
        }
        catch(InterruptedException e){
            throw new RuntimeException(e);
        }
        finally{
            mutex.unlock();
        }
        return element;
    }
}
