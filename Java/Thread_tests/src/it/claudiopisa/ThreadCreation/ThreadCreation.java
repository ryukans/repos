package it.claudiopisa.ThreadCreation;

public class ThreadCreation implements Runnable
{
	public static void main(String args[])
	{
		new ThreadCreation();
	} 
	
	public ThreadCreation()
	{
		Thread main = Thread.currentThread();
		main.setName("Main thread");
		Thread child = new Thread(this, "Child thread");

		System.out.println("Current thread: " + main);
		System.out.println("Created thread: " + child);
		System.out.println();
		
		child.start(); // calls the -run- method
		try {
			Thread.sleep(3000);
			System.out.println("Hey");
		}
		catch (InterruptedException e) {
			System.out.println("Main thread interrupted");
		}
		System.out.println("End main thread");
	}
	

	@Override
	public void run()
	{	
		try {
			for (int i = 5; i > 0; --i) {
				System.out.println(i);
				Thread.sleep(1000);
			}
		}
		catch (InterruptedException e) {
			System.out.println("Child thread interrupted");
		}
		System.out.println("End child thread");
	}

}
