package it.claudiopisa.HashTable;

import java.util.Hashtable;
import java.util.Date;

public class Test
{
	@SuppressWarnings({ "rawtypes", "unchecked" })
	public static void main(String[] args)
	{
		Hashtable table = new Hashtable();
		
		table.put("1", "la data attuale è ");
		table.put("2", new Date());
		table.put("3", table);
		
		for (int i = 0; i <= table.size(); i++)
			System.out.println(table.get("" + i));
	}
}
