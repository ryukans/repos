public class Consumer extends Thread
{
    Buffer buffer;

    public Consumer(Buffer buffer, String name)
    {
        super(name);
        this.buffer = buffer;
    }

    public void run()
    {
        buffer.consume();
    }
}
