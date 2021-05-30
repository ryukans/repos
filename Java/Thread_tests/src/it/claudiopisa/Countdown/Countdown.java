package it.claudiopisa.Countdown;

public class Countdown
{
	final String DEFAULT_COUNTDOWN_MESSAGE = "Starting in\n";
	private Thread counter = Thread.currentThread();
	private int time;
	private long delay;
	
	/* With these constructors you dont need a try-catch block when you create a new instance 

	public Countdown(String message, int time, long delay)
	{
		setCountdownMessage(message);
		try {
			setCountdown(time);
			setDelay(delay);
		}
		catch (CountdownException exc) {
			System.out.println(exc);
			exc.printStackTrace();
		}
	}
	*/
	
	/*
	public Countdown(int time, long delay)
	{
		try {
			setCountdown(time);
			setDelay(delay);
		}
		catch (CountdownException exc) {
			System.out.println(exc);
			exc.printStackTrace();
		}
	}
	*/
	
	public Countdown(String message, int time, long delay) throws CountdownException
	{
		setCountdownMessage(message);
		setCountdown(time);
		setDelay(delay);
	}
	
	public Countdown(int time, long delay) throws CountdownException
	{
		setCountdown(time);
		setDelay(delay);
	}
	
	
	
	public void setCountdown(int time) throws CountdownException
	{
		if (time < 0) throw new CountdownException("Error -- bad time value");
		
		this.time = time;
	}
	
	@SuppressWarnings("static-access")
	public void getCountdown() throws CountdownException
	{
		try {
			for (int time = this.time; time > 0; --time) {
				System.out.println(time);
				counter.sleep(getDelay());
			}
		}
		catch (InterruptedException exc) {
			throw new CountdownException("Error -- countdown interrupted\n" + exc.toString());
		}
	}
	
	
	public void setDelay(long delay) throws CountdownException 
	{
		if (delay < 0) throw new CountdownException("Error -- bad delay value");
		
		this.delay = delay;
	}
	
	public long getDelay() {
		return this.delay;
	}
	
	
	public void setCountdownMessage(String message)
	{	
		try {
			this.counter.setName(message);
		}
		catch (NullPointerException exc) {
			this.counter.setName(DEFAULT_COUNTDOWN_MESSAGE);
		}
	}
	
	
	public String getCountdownMessage() {
		return this.counter.getName();
	}
	
 }


