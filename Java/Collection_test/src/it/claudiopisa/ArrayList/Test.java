package it.claudiopisa.ArrayList;

import java.util.ArrayList;

public class Test 
{
	public static void main(String[] args) 
	{
		// initial capacity is 1
		ArrayList<String> list = new ArrayList<String>(1);
		long startTime = System.currentTimeMillis();
		
		//list.ensureCapacity(100000);
		for (int i = 0; i < 100000; i++)
			list.add("nuovo elemento");
		
		long endTime = System.currentTimeMillis();
		System.out.println("Tempo = " + (endTime - startTime)); 

	}

}
