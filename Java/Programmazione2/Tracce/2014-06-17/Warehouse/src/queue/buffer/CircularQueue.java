package queue.buffer;

import queue.adt.Queue;

public class CircularQueue implements Queue
{
    private final int[] buffer;
    private final int size;
    private int count;
    private int head;
    private int tail;

    public CircularQueue(int size)
    {
        buffer = new int[size];
        this.size = size;
        count = head = tail = 0;
    }

    @Override
    public void push(int value)
    {
        buffer[tail] = value;

        tail = (tail+1)%size;
        ++count;
    }

    @Override
    public int pop()
    {
        int value = buffer[head];

        head = (head+1)%size;
        --count;

        return value;
    }

    @Override
    public boolean full() {
        return count == size;
    }

    @Override
    public boolean empty() {
        return count == 0;
    }

    @Override
    public int size() {
        return size;
    }
}
