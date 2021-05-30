package it.claudiopisa.test;

import java.util.ArrayList;

import it.Geometry.subclasses.quadrilaterals.Square;
import it.Geometry.subclasses.quadrilaterals.Trapezoid;
import it.Geometry.subclasses.quadrilaterals.Triangle;
import it.claudiopisa.subclasses.*;

public class Test
{
	public static void main(String[] args)
	{
		ArrayList<Double> sides = new ArrayList<Double>();
		
		sides.add(12.0);
		sides.add(10.0);
		sides.add(7.0);
		sides.add(9.0);
		
		Trapezoid trp = new Trapezoid(sides);
		
		System.out.println("+------+\n");
		
		System.out.format("TRAPEZOID\n\n"
				+ "Number of sides: %d\nNumber of angles: %d\n\n"
				+ "Perimeter: %.3f\nArea: %.3f\n", 
				trp.getSides(), trp.getAngles(),
				trp.calculatePerimeter(), trp.calculateArea());
		
		System.out.println("\n+------+\n");
		
		sides.clear();
		
		sides.add(15.0);
		sides.add(15.0);
		sides.add(15.0);
		sides.add(15.0);
		
		Square sqr = new Square(sides);
		
		System.out.format("SQUARE\n\n"
				+ "Number of sides: %d\nNumber of angles: %d\n\n"
				+ "Perimeter: %.3f\nArea: %.3f\n",
				sqr.getSides(), sqr.getAngles(),
				sqr.calculatePerimeter(), sqr.calculateArea());
		
		System.out.println("\n+------+\n");
		
		sides.clear();
		
		sides.add(10.0);
		sides.add(10.0);
		sides.add(10.0);
		
		Triangle trn = new Triangle(sides);
		
		System.out.format("TRIANGLE\n\n"
				+ "Number of sides: %d\nNumber of angles: %d\n\n"
				+ "Perimeter: %.3f\nArea: %.3f\n",
				trn.getSides(), trn.getAngles(),
				trn.calculatePerimeter(), trn.calculateArea());
		
		System.out.println("\n+------+\n");
		
		System.exit(0);
	}
}

