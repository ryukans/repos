package ThreadPipe;

import java.io.PipedOutputStream;

public class Main
{
    public static void main(String[] args)
    {
        PipedOutputStream out = new PipedOutputStream();

        WriterThread w = new WriterThread(out);
        ReaderThread r = new ReaderThread(out);

        w.start();
        r.start();
    }
}
