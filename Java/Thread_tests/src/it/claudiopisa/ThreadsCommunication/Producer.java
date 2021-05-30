package it.claudiopisa.ThreadsCommunication;

public class Producer implements Runnable
{
	private WareHouse wareHouse;
	
	public Producer(WareHouse wareHouse) 
	{
		this.wareHouse = wareHouse;
		new Thread(this, "Producer").start();
	}

	@Override
	public void run()
	{
		for (int id = 1; id <= 10; ++id)
			this.wareHouse.put(id);
	}
}
