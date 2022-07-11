package queueImpl;

import queue.MyQueue;

public class CircularQueue implements MyQueue
{
    private int queue[];
    //Capacity
    private int size;

    //Usage; number of elements queued
    private int count;

    private int head;
    private int tail;

    public CircularQueue(int size)
    {
        this.size = size;
        count = head = tail = 0;
        queue = new int[this.size];
    }

    @Override
    public void insert(int element)
    {
        queue[tail] = element;
        tail = (tail+1)%size;
        ++count;
    }

    @Override
    public int get()
    {
        int element = queue[head];

        head = (head+1)%size;
        --count;

        return element;
    }

    @Override
    public boolean isEmpty(){
        return count == 0;
    }

    @Override
    public boolean isFull(){
        return count == size;
    }

    @Override
    public int getSize(){
        return size;
    }
}
