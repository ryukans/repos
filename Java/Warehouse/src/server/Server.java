package server;

public class Server
{
    public static void main(String[] args)
    {
        TechWarehouse server = new TechWarehouse(8000);

        server.runSkeleton();
    }
}
