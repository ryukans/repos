package it.Geometry.subclasses.triangles;

import java.util.ArrayList;

/**
 * 
 * @author Claudio Pisa
 *
 */
public class Equilateral extends Isosceles
{
	public final String NAME = "Equilateral triangle";
	
	/**
	 * 
	 * @param sidesMeasures: the measures of the triangle's sides.
	 * @see it.Geometry.subclasses.Triangle#Triangle(ArrayList)
	 */
	public Equilateral(ArrayList<Double> sidesMeasures)
	{ 
		super(sidesMeasures);
		if(!isEquilateral()){
			System.out.println("Error: the triangle is not an equilateral !\nwrong measures");
			super.sidesMeasures.clear();
		}
		else
			super.polygonName = NAME;
	}
	
	
	/**
	 * 
	 * @return <pre>
	 * <b>{@code true}</b> if the triagle is an equilateral (all the sides measures equal);
	 * <b>{@code false}</b> otherwise.
	 * </pre>
	 */
	private boolean isEquilateral()
	{
		Double a = sidesMeasures.get(0), 
			   b = sidesMeasures.get(1), 
			   c = sidesMeasures.get(2);
		
		if(a.equals(b) && a.equals(c) && b.equals(c))
			return true;
		else
			return false;
	}
	

	/**
	 * @return the perimeter of the triangle.
	 * @see it.geometry.superclasses.Polygon#calculatePerimeter(){@link #calculatePerimeter()} //???
	 */
	@Override
	public Double calculatePerimeter()
	{ return sidesMeasures.get(0)*3; }
}

