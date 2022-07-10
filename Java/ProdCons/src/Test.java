import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Test
{
    public static void main(String[] args)
    {
        /*
        * Creating shared buffer.
        * */
        Buffer buffer = new Buffer();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        boolean on = true;
        char choice = '\0';
        do{
            do{
                System.out.print("1.Produce item\n2.Consumer item\n3.Quit\n> ");
                try{
                    choice = br.readLine().charAt(0);
                }catch(IOException e){
                    e.printStackTrace();
                }
            }while(choice != '1' && choice != '2' && choice != '3');

            switch(choice){
                case '1' ->{
                    Producer prod = new Producer(buffer, "Producer");
                    prod.start();
                }
                case '2' ->{
                    Consumer cons = new Consumer(buffer, "Consumer");
                    cons.start();
                }
            }
        }while(choice != '3');
    }
}
