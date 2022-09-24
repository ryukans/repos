package queue;

public abstract class QueueWrapper implements Queue
{
    protected Queue queue;

    public QueueWrapper(Queue queue){
        this.queue = queue;
    }

    @Override
    public void push(int element){
        queue.push(element);
    }

    @Override
    public int pop() {
        return queue.pop();
    }

    @Override
    public int size() {
        return queue.size();
    }

    @Override
    public boolean isEmpty(){
        return queue.isEmpty();
    }

    @Override
    public boolean isFull(){
        return queue.isFull();
    }
}
