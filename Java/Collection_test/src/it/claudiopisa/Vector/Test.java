package it.claudiopisa.Vector;

import java.util.Vector;

public class Test
{
	public static void main(String[] args)
	{
		Vector<String> list = new Vector<String>(10,10);
		
		for (int i = 0; i < 11; i++)
			list.add("1");
		
		System.out.println("Capacità = " + list.capacity());
		
		for (int i = 0; i < 11; i++)
			list.add("1");
		
		
		System.out.println("Capacità = " + list.capacity()); 
	}
}
