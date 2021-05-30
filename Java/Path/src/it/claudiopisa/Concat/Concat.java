package it.claudiopisa.Concat;

import java.nio.file.Path;
import java.nio.file.Paths;

public class Concat {

	public static void main(String[] args) {
		// Solaris
		Path p0 = Paths.get("/home/joe/foo");
		
		// Result is /home/joe/foo/bar
		System.out.format("%s%n", p0.resolve("bar"));

		
		
		// Microsoft Windows
		Path p1 = Paths.get("C:\\home\\joe\\foo");
		
		// Result is C:\home\joe\foo\bar
		System.out.format("%s%n", p1.resolve("bar"));

	}

}
