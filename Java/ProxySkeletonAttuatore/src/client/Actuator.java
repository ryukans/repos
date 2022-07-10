package client;

import dispatcher.*;

import java.io.*;

public class Actuator {

    /**
     * @param args
     */
    public static void main(String[] args)
    {
        Dispatchable dispatcher = new DispatcherProxy ("127.0.0.1", 8000);

        int cmd = 0;

        try{
            FileOutputStream fileOut = new FileOutputStream("./cmdlog.txt");
            PrintStream outStream = new PrintStream(fileOut);

            while(true){
                cmd = dispatcher.getCmd();
                System.out.println("[Actuator] - command received: " + cmd);
                outStream.println("command = " + cmd);
                Thread.sleep(5000);
            }
        }
        catch(IOException e){
            e.printStackTrace();
        }
        catch(InterruptedException i){
            i.printStackTrace();
        }
    }
}
