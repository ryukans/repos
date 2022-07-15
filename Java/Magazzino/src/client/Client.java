package client;

public class Client
{
    public static void main(String[] args)
    {
        Thread sender = new Thread(new Sender());
        Thread receiver = new Thread(new Receiver());

        sender.start();
        receiver.start();
    }
}
