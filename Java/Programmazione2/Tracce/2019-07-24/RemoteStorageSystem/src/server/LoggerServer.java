package server;

import interfaces.Logger;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;

public class LoggerServer implements Logger
{
    @Override
    public void storeData(int data)
    {
        try{
            FileOutputStream file = new FileOutputStream("./logs.txt");
            PrintStream out = new PrintStream(file);

            out.println(data);
            out.flush();

            System.out.println("Data stored on file: " + data);
        }
        catch(FileNotFoundException e){
            throw new RuntimeException(e);
        }
    }
}
