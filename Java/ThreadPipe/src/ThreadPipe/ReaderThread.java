package ThreadPipe;

import java.io.*;

public class ReaderThread extends Thread
{
    private DataInputStream dataIn;

    public ReaderThread(PipedOutputStream out)
    {
        try {
            dataIn = new DataInputStream(new PipedInputStream(out));
        }
        catch (IOException exc){
            exc.printStackTrace();
        }
    }

    public void run()
    {
        String s;

        while(true){
            try {
                System.out.println("[Reader]: reading string");
                s = dataIn.readUTF();
                System.out.println("[Reader]: string: " + s);
            }
            catch (IOException exc){
                exc.printStackTrace();
            }
        }
    }
}
