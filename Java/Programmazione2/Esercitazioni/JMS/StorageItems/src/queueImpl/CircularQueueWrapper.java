package queueImpl;

import java.util.concurrent.locks.*;

import queue.*;

public class CircularQueueWrapper extends QueueWrapper
{
    private Lock lock;
    private Condition empty;
    private Condition full;

    public CircularQueueWrapper(MyQueue queue)
    {
        super(queue);

        lock = new ReentrantLock();
        empty = lock.newCondition();
        full = lock.newCondition();
    }


    public void insert(int i)
    {
        lock.lock();

        try{
            while(queue.isFull()){
                try{
                    empty.await();
                }
                catch(InterruptedException e){
                    e.printStackTrace();
                }
            }

            queue.insert(i);
            full.signal();

        }
        finally{
            lock.unlock();
        }
    }


    public int preleva()
    {
        int element;

        lock.lock();

        try{
            while(queue.isEmpty()){
                try{
                    full.await();
                }
                catch(InterruptedException e){
                    e.printStackTrace();
                }
            }

            element = queue.get();
            empty.signal();
        }
        finally{
            lock.unlock();
        }
        return element;
    }
}
