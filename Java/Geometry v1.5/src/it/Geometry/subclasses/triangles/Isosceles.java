package it.Geometry.subclasses.triangles;

import java.util.ArrayList;


/**
 * 
 * @author Claudio Pisa
 * @see it.Geometry.subclasses.triangles.Triangle
 */
public class Isosceles extends Triangle
{
	public final String NAME = "Triangle isosceles";
	/**
	 * 
	 * @param sidesMeasures: the measures of the triangle's sides.
	 * @see it.Geometry.subclasses.Triangle#Triangle(ArrayList)
	 */
	public Isosceles(ArrayList<Double> sidesMeasures)
	{ 
		super(sidesMeasures);
		super.polygonName = NAME;
	}
	
	
	/**
	 * 
	 * @return <pre>
	 * <b>{@code true}</b> if the triangle is an isosceles;
	 * <b>{@code false}</b> otherwise
	 * </pre>
	 */
	@SuppressWarnings("unused")
	private boolean isIsosceles() // TODO: complete this method
	{ return false; }
}

