package server;

import interfaces.Logger;

public class Start
{
    public static void main(String[] args)
    {
        LoggerServerSkeleton logger = new LoggerServerSkeleton(new LoggerServer(), 3000);

        logger.runSkeleton();
    }
}
