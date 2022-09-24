package queue.adt;

public interface Queue
{
    void push(int value);
    int pop();
    boolean full();
    boolean empty();
    int size();
}
