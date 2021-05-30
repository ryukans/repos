package it.claudiopisa.TreeSet;

import java.util.Iterator;
import java.util.TreeSet;

public class Test
{
	public static void main(String[] args)
	{
		TreeSet<String> set = new TreeSet<String>();
		set.add("c");
		set.add("a");
		set.add("b");
		set.add("b");
		
		Iterator<String> iter = set.iterator();
		while (iter.hasNext())
			System.out.println(iter.next());
	}
}
