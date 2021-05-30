package it.claudiopisa.SynchronizedTest;

public class Caller implements Runnable 
{
	private String msg;
	private CallMe target;
	
	public Caller(CallMe target, String msg)
	{
		this.target = target;
		this.msg = msg;
		new Thread(this).start();
	}
	
	
	@Override
	public void run()
	{
		synchronized (this.target) {
			this.target.call(this.msg);
		}
	}

}
