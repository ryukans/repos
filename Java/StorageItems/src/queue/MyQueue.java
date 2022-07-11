package queue;

public interface MyQueue
{
    void insert(int element);
    int get();
    boolean isEmpty();
    boolean isFull();
    int getSize();
}
