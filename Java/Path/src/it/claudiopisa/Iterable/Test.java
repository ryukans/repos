package it.claudiopisa.Iterable;

import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Iterator;

public class Test
{
	public static void main(String[] args)
	{
		Path path = Paths.get("C:\\Users\\Claudio Pisa\\Desktop");
		
		//while loop test
		
		Iterator<Path> i = path.iterator();
		while (i.hasNext()) {
			Path dir = (Path) i.next();
			System.out.format("Current directory: %s%n", dir);
		}
		
		System.out.println();
		
		//for loop test
		
		for (Iterator<Path> iterator = path.iterator(); iterator.hasNext();) {
			Path dir = (Path) iterator.next(); //with Generics, casting is not necessary
			System.out.format("Current directory: %s%n", dir);
		}
	
		//for each loop test
		
		for (Path dir : path) {
			System.out.format("Current directory: %s%n", dir);
		}
	}
}


