package it.claudiopisa.PathConverting;

import java.nio.file.Path;
import java.nio.file.Paths;

public class PathConverting
{
	public static void main(String[] args)
	{
		Path p1 = Paths.get("/home/logfile");
		
		// Result is file:///home/logfile
		System.out.format("%s%n", p1.toUri());
	}
}
