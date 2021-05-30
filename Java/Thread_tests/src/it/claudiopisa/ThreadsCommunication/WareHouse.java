package it.claudiopisa.ThreadsCommunication;

public class WareHouse
{
	private int numberOfProducts;
	private int idProduct;
	private boolean empty = true; // warehouse is empty
	
	/* default constructor */
	
	public synchronized void put(int idProduct) // called by -Producer-
	{
		if (!empty) 
			try {
				wait();
			}
			catch (InterruptedException e) {
				e.printStackTrace();
			}
		
		this.idProduct = idProduct;
		++numberOfProducts;
		printSituation("Produced " + idProduct);
		empty = false;
		notify(); // wakes -Consumer-
	}
	
	public synchronized int get() // called by -Consumer-
	{
		if (empty) 
			try {
				wait();
			}
			catch (InterruptedException e) {
				e.printStackTrace();
			}
		
		--numberOfProducts;
		printSituation("Consumed " + this.idProduct); 
		empty = true;
		notify(); // wakes -Producer-
		
		return this.idProduct;
	}
	
	public void printSituation(String message) {
		System.out.println(message + '\n' + this.numberOfProducts + " products in warehouse\n");
	}
	
	
}
