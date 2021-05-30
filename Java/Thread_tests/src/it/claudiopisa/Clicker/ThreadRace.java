package it.claudiopisa.Clicker;

public class ThreadRace
{
	public static void main(String[] args)
	{
		Thread.currentThread().setPriority(Thread.MAX_PRIORITY); //10
		
		Clicker lo = new Clicker(Thread.NORM_PRIORITY - 2); //3
		Clicker hi = new Clicker(Thread.NORM_PRIORITY + 2); //7
		
		lo.startThread();
		hi.startThread();
		
		try {
			Thread.sleep(10000);
		}
		catch (Exception e) {}
		
		lo.stopThread();
		hi.stopThread();
		
		System.out.println(lo.getClick() + " vs." + hi.getClick());
	}
}




