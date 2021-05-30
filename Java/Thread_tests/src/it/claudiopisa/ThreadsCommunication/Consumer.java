package it.claudiopisa.ThreadsCommunication;

public class Consumer implements Runnable
{
	private WareHouse wareHouse;
	
	public Consumer(WareHouse wareHouse)
	{
		this.wareHouse = wareHouse;
		new Thread(this, "Counsumer").start();
	}

	@Override
	public void run() 
	{
		for (int id = 0; id < 10; ++id)
			id = this.wareHouse.get();		
	}
}
