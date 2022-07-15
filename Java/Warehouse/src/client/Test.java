package client;

import interfaces.Warehouse;
import server.TechWarehouse;

public class Test
{
    public static void main(String[] args)
    {
        Warehouse server = new Proxy("127.0.0.1", 8000);

        ClientA[] tClientA = new ClientA[5];
        ClientB[] tClientB = new ClientB[5];

        for(int i = 0; i < 5; i++){
            tClientA[i] = new ClientA(server);
            tClientA[i].start();
        }

        for(int i = 0; i < 5; i++){
            tClientB[i] = new ClientB(server);
            tClientB[i].start();
        }

    }
}
