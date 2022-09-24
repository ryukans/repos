package client;

import interfaces.Warehouse;

import java.util.Random;

public class ClientA extends Thread
{
    private Warehouse warehouse;

    public ClientA(Warehouse warehouse){
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
            int id = new Random().nextInt(1, 100);

            warehouse.deposit(item, id);
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

            id = rand.nextInt(100) +1;

            if(Math.random()<0.5)
                articolo = "laptop";
            else
                articolo = "smartphone";

            warehouse.deposit(articolo, id);

            System.out.println("[CLIENT_A] depositato articolo: "+articolo+" con id: "+id);

        }
    }
}
