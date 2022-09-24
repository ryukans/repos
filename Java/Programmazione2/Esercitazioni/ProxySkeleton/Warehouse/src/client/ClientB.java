package client;

import interfaces.Warehouse;

import java.util.Random;

public class ClientB extends Thread
{
    Warehouse warehouse;

    public ClientB(Warehouse warehouse){
        this.warehouse = warehouse;
    }

    /*
    public void run()
    {
        for(int i = 0; i < 3; i++){
            int t = new Random().nextInt(2, 4);

            try {
                Thread.sleep(t * 1000L);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

            String item = new Random().nextInt() % 2 == 0 ? "laptop" : "smartphone";

            warehouse.withdraw(item);
        }
    }*/

    public void run()
    {
        Random rand = new Random();
        int id;
        String articolo;

        for(int i=0; i<3; i++) {

            try {
                sleep((rand.nextInt(3)+2)*1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }

            if(Math.random()<0.5)
                articolo = "laptop";
            else
                articolo = "smartphone";

            id = warehouse.withdraw(articolo);

            System.out.println("[CLIENT_B] prelevato articolo: "+articolo+" con id: "+id);

        }
    }
}
