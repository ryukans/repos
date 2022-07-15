package printer;

import interfaces.printer.IPrinter;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Random;
import java.util.concurrent.Semaphore;

public class Printer implements IPrinter
{
    private Semaphore mutex;

    public Printer(){
        mutex = new Semaphore(1);
    }

    @Override
    public boolean print(String docName)
    {
        if(!mutex.tryAcquire())
            return false;

        try{
            FileOutputStream out = new FileOutputStream("./file");
            PrintStream outStream = new PrintStream(out);

            int t = new Random().nextInt(5, 10);
            Thread.sleep(t*1000L);

            System.out.println("Doc name: " + docName);
            outStream.println(docName);
        }
        catch(InterruptedException | FileNotFoundException e){
            e.printStackTrace();
        }
        finally{
            mutex.release();
        }

        return true;
    }
}
