package it.claudiopisa.Compare;

import java.nio.file.Path;
import java.nio.file.Paths;

public class Compare
{
	public static void main(String[] args)
	{
		Path p1 = Paths.get("C:\\Users\\Claudio Pisa\\Desktop");
		Path p2 = Paths.get("C:\\Users\\Claudio Pisa");
		Path beginning = Paths.get("C:\\Users");
		Path ending = Paths.get("Desktop");
		
		if (p1.equals(p2)) {
			System.out.println("Same paths");
		} else if (p1.startsWith(beginning)) {
			System.out.println("Path starts with " + beginning.toString());
		} else if (p1.endsWith(ending)) {
			System.out.println("Path ends with " + ending.toString());
		}
		
		
	}
}