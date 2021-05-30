package it.claudiopisa.superclasses;

import java.util.ArrayList;
import java.util.Iterator;


public class Polygon 
{
	private int numSides, numAngles; /* -numAngles- doesn't have an effective scope in this program */
	protected ArrayList<Double> sides = new ArrayList<Double>();
	
	protected void setSides(int numSides)
	{ this.numSides = numSides; }
	
	public int getSides()
	{ return numSides; }
	
	
	protected void setAngles(int numAngles)
	{ this.numAngles = numAngles; }
	
	public int getAngles()
	{ return numAngles; }
	
	
	@SuppressWarnings("rawtypes")
	public double calculatePerimeter()
	{
		Iterator index; /* needed to loop through the array list */
		double p = 0.0; /* -p- stores the perimeter */
		
		index = sides.iterator();
		while(index.hasNext()){
			p += (double) index.next();
		}
		return p;
	}
}

