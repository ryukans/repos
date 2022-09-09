package server;

public class Start
{
    public static void main(String[] args)
    {
        SkeletonLogger logger = new SkeletonLogger(new LoggerServer(), 3000);

        logger.runSkeleton();
    }
}
