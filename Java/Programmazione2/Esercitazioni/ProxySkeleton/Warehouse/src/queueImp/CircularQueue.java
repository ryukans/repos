package queueImp;

import queue.Queue;

public class CircularQueue implements Queue
{
    private int[] queue;
    private int size;
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
    public void push(int element)
    {
        try{
            Thread.sleep(101 + (int)(Math.random()*100)  ); //sleep di durata random max pari a 200ms
        }catch ( InterruptedException e ){
            e.printStackTrace();
        }

        queue[tail] = element;

        tail = (tail+1)%size;
        ++count;
    }

    @Override
    public int pop()
    {
        try{
            Thread.sleep(101 + (int)(Math.random()*100)  ); //sleep di durata random max pari a 200ms
        }catch ( InterruptedException e ){
            e.printStackTrace();
        }

        int element = queue[head];

        head = (head+1)%size;
        --count;

        return element;
    }

    @Override
    public int size(){
        return size;
    }

    @Override
    public boolean isEmpty(){
        return count == 0;
    }

    @Override
    public boolean isFull(){
        return count == size;
    }
}
