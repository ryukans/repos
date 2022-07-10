/**
 * <p>
 * Implementation of a single item buffer.
 * </p>
 */
public class Buffer
{
    private long item;
    private boolean full;

    /**
     * <p><b>false</b>: buffer's item's not been produced yet</p>
     * <p><b>true</b>: buffer's item's been produced</p>
     * <p>The initial condition, <em>full</em>, is false.</p>
     */
    public Buffer()
    {
        item = 0;
        full = false;
    }

    public synchronized void produce()
    {
        System.out.println(Thread.currentThread().getName() + ":  invocazione produci");

        while(full){
            System.out.println(Thread.currentThread().getName() + ":  in attesa (buffer pieno)");
            try{
                wait();
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }
        item = System.currentTimeMillis();

        System.out.println(Thread.currentThread().getName() + ":  prodotto = " + item);

        /*
         * Item's just been produced, update condition variable value.
         * */
        full = true;
        notifyAll();
    }

    public synchronized void consume()
    {
        System.out.println(Thread.currentThread().getName() + ":  invocazione consuma");

        while(!full){
            System.out.println(Thread.currentThread().getName() + ":  in attesa (buffer vuoto)");
            try{
                wait();
            }catch(InterruptedException e){
                e.printStackTrace();
            }
        }

        System.out.println(Thread.currentThread().getName() + ":  consumato = " + item);

        /*
         * Item's just been consumed, update condition variable value.
         * */
        full = false;
        notifyAll();
    }
}
