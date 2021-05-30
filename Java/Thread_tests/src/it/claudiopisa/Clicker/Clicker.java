package it.claudiopisa.Clicker;

public class Clicker implements Runnable
{
	private int click = 0;
	private Thread t;
	private boolean running = true;
	
	public Clicker(int priority)
	{
		t = new Thread(this);
		t.setPriority(priority);
	}
	
	public int getClick() {
		return click; 
	}
	
	@Override
	public void run()
	{
		while (running) {
			++click;
		}
	}
	
	public void startThread() {
		t.start();
	}
	
	public void stopThread() {
		running = false;
	}
}




