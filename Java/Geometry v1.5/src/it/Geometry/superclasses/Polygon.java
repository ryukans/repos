package it.Geometry.superclasses;

import java.util.ArrayList;
import java.util.Iterator;

/**
 * 
 * @author Claudio Pisa
 *
 */
public abstract class Polygon
{
	protected ArrayList<Double> sidesMeasures = new ArrayList<Double>();
	protected int numberOfSides, numberOfAngles;
	protected String polygonName = null; /* this will be inherited by the other classes
										  * and than it will be equal to the default name of the polygon
										  */
	

	/**
	 * 
	 * @return Triangle perimeter
	 */
	protected Double calculatePerimeter()
	{
		Iterator<Double> index; /* needed to loop through the array list */
		Double p = 0.0; /* stores the perimeter */
		
		index = sidesMeasures.iterator();
		while(index.hasNext())
			p += (Double) index.next();
		
		return p;
	}
	
	
	/**
	 * 
	 * @return Triangle area
	 */
	protected abstract Double calculateArea();
	
	
	/**
	 * 
	 * @param polygonName: name of the polygon
	 * @param genericPolygon (polimorphic argument)
	 */
	public void printInfo(String polygonName, Polygon genericPolygon)
	{
		if(sidesMeasures.isEmpty())
			System.out.format("\nInfos for %s are not avaible!\n\n", polygonName);
		else{
			/* version 1
			System.out.println(polygonName + "\n\n"
					+ "Number of sides: " + genericPolygon.numberOfSides+ '\n'
					+ "Number of angles: " + genericPolygon.numberOfAngles + '\n'
					+ "Perimeter: " + String.format("%.3f", genericPolygon.calculatePerimeter()) +'\n'
					+ "Area: " + String.format("%.3f", genericPolygon.calculateArea()));
			*/
			
			/* version 2
			System.out.println(polygonName + "\n\n"
					+ "Number of sides: " + genericPolygon.numberOfSides+ '\n'
					+ "Number of angles: " + genericPolygon.numberOfAngles+ '\n'
					+ "Perimeter: " + genericPolygon.calculatePerimeter() +'\n'
					+ "Area: " + genericPolygon.calculateArea());
			*/
			
			/* version 3 (with -format- or -printf- methods)*/
			System.out.format("\n------\n"
					+ "Name: %s\n\n"
					+ "Number of sides: %d\n"
					+ "Number of angles: %d\n\n"
					+ "Perimeter: %.3f\n"
					+ "Area: %.3f\n", 
					polygonName,
					genericPolygon.numberOfSides,
					genericPolygon.numberOfAngles,
					genericPolygon.calculatePerimeter(),
					genericPolygon.calculateArea());
			
			
		}
		System.out.println("------\n");
	}
	
	/**
	 * 
	 * @param genericPolygon (polimorphic argument)
	 */
	public void printInfo(Polygon genericPolygon)
	{
		if(sidesMeasures.isEmpty())
			System.out.format("\nInfos for %s are not avaible!\n\n", genericPolygon.polygonName);
		else{
			System.out.format("\n------\n"
					+ "Name: %s\n\n"
					+ "Number of sides: %d\n"
					+ "Number of angles: %d\n\n"
					+ "Perimeter: %.3f\n"
					+ "Area: %.3f\n", 
					genericPolygon.polygonName,
					genericPolygon.numberOfSides,
					genericPolygon.numberOfAngles,
					genericPolygon.calculatePerimeter(),
					genericPolygon.calculateArea());
		}
		System.out.println("------\n");
	}
	
	
	public void printInfo()
	{
		
	}
}


/*
	private final int MIN_NUMBER_OF_SIDES = 3, MIN_NUMBER_OF_ANGLES = 3;
    private int numberOfSides, numberOfAngles;
    
    protected void setNumberOfSides(int numberOfSides)
	{
		if(numberOfSides >= MIN_NUMBER_OF_SIDES)
			this.numberOfSides = numberOfSides;
		else
			this.numberOfSides = 0;
	}
	
	protected int getNumberOfSides()
	{ return numberOfSides; }
	
	
	protected void setNumberOfAngles(int numberOfAngles)
	{ 
		if(numberOfAngles >= MIN_NUMBER_OF_ANGLES)
			this.numberOfAngles = numberOfAngles;
		else
			this.numberOfAngles = 0;
	}
	
	protected int getNumberOfAngles()
	{ return numberOfAngles; }
*/

