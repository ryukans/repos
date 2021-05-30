package it.Geometry.subclasses.triangles;

import java.util.ArrayList;

/**
 * 
 * @author Claudio Pisa
 * @see it.Geometry.subclasses.triangles.Triangle
 */
public class RightTriangle extends Triangle
{
	public final String DEFAULT_NAME = "Right triangle";
	
	
	/**
	 * 
	 * @param sidesMeasures: the measures of the triangle's sides.
	 * @see it.Geometry.subclasses.Triangle#Triangle(ArrayList)
	 */
	public RightTriangle(ArrayList<Double> sidesMeasures)
	{ 
		super(sidesMeasures);
		super.polygonName = DEFAULT_NAME;
	}
}