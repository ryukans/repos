package ThreadPipe;

import java.io.*;

public class WriterThread extends Thread
{
    private DataOutputStream dataOut;

    public WriterThread(PipedOutputStream out)
    {
        dataOut = new DataOutputStream(out);
    }

    public void run()
    {
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        String s;

        while(true){
            try {
                System.out.println("[Writer] enter string: ");
                s = buffer.readLine();
                System.out.println("[Writer] string: " + s);
                dataOut.writeUTF(s);
            }
            catch (IOException exc){
                exc.printStackTrace();
            }
        }
    }
}
