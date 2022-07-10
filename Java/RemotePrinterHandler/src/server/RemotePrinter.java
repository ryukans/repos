package server;

import interfaces.Printer;

import java.io.*;
import java.util.Random;
import java.util.concurrent.Semaphore;

public class RemotePrinter implements Printer
{
    private final Semaphore mutex = new Semaphore(1);

    @Override
    public boolean print(String docName)
    {
        if(!mutex.tryAcquire())
        {
            System.out.println("[Printer]: print request failed");
            return false;
        }

        try{
            FileWriter fw = new FileWriter(docName, true);
            BufferedWriter bw = new BufferedWriter(fw);
            PrintWriter pw = new PrintWriter(bw);

            int t = new Random().nextInt(5, 10);
            Thread.sleep(t*1000L);

            System.out.println("File name: " + docName);
            pw.println(docName);
            pw.flush();

            pw.close();
            bw.close();
            fw.close();
        }
        catch (IOException | InterruptedException e){
            e.printStackTrace();
        }
        finally{
            mutex.release();
        }
        return true;
    }
}
