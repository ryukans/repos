package server;

public class Counter extends CounterSkeleton
{
    private int count;

    public Counter(){
        count = 0;
    }

    @Override
    public synchronized void inc(){
        ++count;
    }

    @Override
    public synchronized void sum(int value){
        count += value;
    }

    @Override
    public int get(){
        return 0;
    }

    @Override
    public synchronized void square(){
        count *= count;
    }
}
