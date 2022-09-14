package sensor;

import java.io.*;
import java.util.Vector;

public class Executor extends Thread
{
    private final Sensor sensor;
    public Executor(){
        sensor = Sensor.getSensor();
    }

    public void run()
    {
        System.out.println("Executor started");

        Vector<String> commands;

        while(true){
            commands = sensor.takeAll();
            if(commands.size() == 0) //TODO: controllare se inutile o ridondante
                continue;

            System.out.println("Executor | commands taken");

            try{
                sleep(10000L);

                PrintStream ps = new PrintStream(
                        new FileOutputStream("./cmdlog.txt", true)
                );

                /*
                * Alternativa con buffered writer (orientato al byte)
                * */
                BufferedWriter bw = new BufferedWriter(
                        new FileWriter("./cmdlog.txt", true));

                /*
                * Alternativa con print writer (orientato al carattere)
                * */
                PrintWriter pw = new PrintWriter(
                        new FileWriter("./cmdlog.txt", true));

                /*
                * Alternativa con print writer con decorator buffered writer
                * */
                PrintWriter out  = new PrintWriter(bw);

                for(String s: commands){
                    System.out.println("Writing on file: " + s);
                    out.println(s);
                    //bw.write(s);
                    //bw.newLine();
                }

                //bw.flush();
                //bw.close();

                out.flush();
                out.close();
            }
            catch(IOException | InterruptedException e){
                throw new RuntimeException(e);
            }
        }
    }
}
