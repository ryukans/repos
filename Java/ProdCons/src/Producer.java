public class Producer extends Thread
{
    private Buffer buffer;

    public Producer(Buffer buffer, String name)
    {
        super(name);
        this.buffer = buffer;
    }

    public void run()
    {
        buffer.produce();
    }
}
