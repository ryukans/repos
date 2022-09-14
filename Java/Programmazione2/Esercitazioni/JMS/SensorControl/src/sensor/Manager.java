package sensor;

import javax.jms.JMSException;
import javax.jms.TextMessage;

public class Manager extends Thread
{
    private final Sensor sensor; //si potrebbe eliminare e ottenere l'istanza direttamente in run()
    private final TextMessage message;

    public Manager(TextMessage message)
    {
        this.sensor = Sensor.getSensor();
        this.message = message;
    }

    @Override
    public void run()
    {
        String command;

        try{
            command = message.getText();
            System.out.println("Received command: " + command);
        }
        catch(JMSException e){
            System.out.println("Invalid reading command; sensor stopped");
            command = "stop";
        }
        sensor.put(command);
    }
}
