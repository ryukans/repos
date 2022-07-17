package server;

import printer.Printer;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class RemotePrinter implements Printer
{
    private final Lock mutex;
    private final Semaphore semaphore;
    public RemotePrinter()
    {
        mutex = new ReentrantLock();
        semaphore = new Semaphore(1);
    }

    @Override
    public boolean print(String docName)
    {
        //if(!mutex.tryLock())
          //  return false;

        if(!semaphore.tryAcquire())
            return false;

        try {
            PrintWriter out = new PrintWriter(new FileWriter("./printer.txt", true));

            System.out.println("Doc name: " + docName);
            out.println(docName);
            out.flush();
            out.close();
        }
        catch(IOException e) {
            throw new RuntimeException(e);
        }
        finally {
            //mutex.unlock();
            semaphore.release();
        }

        return true;
    }
}
