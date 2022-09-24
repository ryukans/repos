package client;

import service.ICounter;

public class Client
{
    public static void main(String[] args)
    {
        String host = args[0];
        String op = args[1];

        if(!op.equalsIgnoreCase("sum") && !op.equalsIgnoreCase("get")&&
            !op.equalsIgnoreCase("sqr") && !op.equalsIgnoreCase("inc")){
            System.out.println("Bad format");
            return;
        }

        ICounter counter = new CounterProxy(host, 2500);

        switch(op.toLowerCase()){
            case "sum" -> {
                try{
                    int value = Integer.parseInt(args[2]);
                    counter.sum(value);
                }
                catch(NumberFormatException e){
                    e.printStackTrace();
                }
            }
            case "get" -> System.out.println("Value: " + counter.get());
            case "sqr" -> counter.square();
            case "inc" -> counter.inc();
        }

    }
}
