package client;

import dispatcher.Dispatchable;

import java.io.*;

public class Actuator
{
    public static void main(String[] args)
    {
        Dispatchable dispatcher =  new DispatcherProxy("172.0.0.1", 8000);
        int command = 0;
        try{
            FileOutputStream fileOut = new FileOutputStream("./cmdlog.txt");
            PrintStream outStream = new PrintStream(fileOut);

            while(true){
                command = dispatcher.getCmd();
                System.out.println("[Actuator] - command: " + command);
                outStream.println(command);
                Thread.sleep(5000);
            }
        } catch (FileNotFoundException | InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
