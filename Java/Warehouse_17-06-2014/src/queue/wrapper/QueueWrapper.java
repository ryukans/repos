package queue.wrapper;

import queue.adt.Queue;

public abstract class QueueWrapper implements Queue
{
    protected Queue queue;

    public QueueWrapper(Queue queue){
        this.queue = queue;
    }

    @Override
    public void push(int value) {
        queue.push(value);
    }

    @Override
    public int pop() {
        return queue.pop();
    }

    @Override
    public boolean full() {
        return queue.full();
    }

    @Override
    public boolean empty() {
        return queue.empty();
    }

    @Override
    public int size() {
        return queue.size();
    }
}
