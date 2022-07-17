package queue.monitor;

import queue.adt.Queue;
import queue.wrapper.QueueWrapper;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class QueueMonitor extends QueueWrapper
{
    private final Lock monitor;
    private final Condition producer;
    private final Condition consumer;

    public QueueMonitor(Queue queue)
    {
        super(queue);
        monitor = new ReentrantLock();
        producer = monitor.newCondition();
        consumer = monitor.newCondition();
    }

    @Override
    public void push(int value)
    {
        monitor.lock();
        try {
            while(queue.full()) {
                try {
                    producer.await();
                }
                catch(InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }

            queue.push(value);
            System.out.println("Pushed");
            consumer.signal();
        }
        finally {
            monitor.unlock();
        }
    }

    public int pop()
    {
        int value;
        monitor.lock();

        try {
            while(queue.empty()) {
                try {
                    consumer.await();
                }
                catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }

            value = queue.pop();
            producer.signal();
        }
        finally {
            monitor.unlock();
        }

        return value;
    }

    @Override
    public boolean empty() {
        return queue.empty();
    }

    @Override
    public boolean full() {
        return queue.full();
    }

    @Override
    public int size() {
        return queue.size();
    }
}
