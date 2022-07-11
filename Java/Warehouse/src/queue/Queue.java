package queue;

public interface Queue
{
    void push(int element);
    int pop();
    int size();
    boolean isEmpty();
    boolean isFull();
}
