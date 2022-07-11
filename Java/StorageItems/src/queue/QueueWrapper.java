package queue;

public class QueueWrapper implements MyQueue
{
    protected MyQueue queue;

    public QueueWrapper(MyQueue queue)
    {
        this.queue = queue;
    }

    @Override
    public void insert(int element){
        queue.insert(element);
    }

    @Override
    public int get(){
        return queue.get();
    }

    @Override
    public boolean isEmpty(){
        return queue.isEmpty();
    }

    @Override
    public boolean isFull(){
        return queue.isFull();
    }

    @Override
    public int getSize(){
        return queue.getSize();
    }
}
