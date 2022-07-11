package server;

public class Server
{
    public static void main(String[] args)
    {
        ServerSkeleton server = new ServerSkeleton(8000);

        server.runSkeleton();
    }
}
