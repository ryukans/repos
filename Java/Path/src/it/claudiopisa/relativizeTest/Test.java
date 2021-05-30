package it.claudiopisa.relativizeTest;

import java.nio.file.Path;
import java.nio.file.Paths;

public class Test
{
	public static void main(String[] args)
	{
		/* Example 1 */
		
		Path p1 = Paths.get("foo");
		Path p2 = Paths.get("bar");
		
		Path p1_to_p2 = p1.relativize(p2);
		Path p2_to_p1 = p2.relativize(p1);
		
		System.out.format("p1> %s%np2> %s%n", p1, p2);
		System.out.format("%s%n%s%n", p1_to_p2, p2_to_p1);
		
		System.out.println();
		
		/* Example 2 */
		
		Path p3 = Paths.get("C:\\Users");
		Path p4 = Paths.get("C:\\Users\\Claudio Pisa\\Desktop");
		
		Path p3_to_p4 = p3.relativize(p4);
		Path p4_to_p3 = p4.relativize(p3);
		
		System.out.format("p3> %s%np4> %s%n", p3, p4);
		System.out.format("%s%n%s%n", p3_to_p4, p4_to_p3);
	}
}
