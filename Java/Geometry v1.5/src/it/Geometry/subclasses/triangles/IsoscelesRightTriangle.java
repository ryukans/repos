package it.Geometry.subclasses.triangles;

import java.util.ArrayList;
import it.Geometry.interfaces.RightTriangleInterface;


/**
 * 
 * @author Claudio Pisa
 * @see it.Geometry.interfacce.RightTriangleInterface
 * @see it.Geometry.subclasses.triangles.Isosceles
 */
public class IsoscelesRightTriangle
extends Isosceles 
implements RightTriangleInterface
{
	public final String name = "Isosceles right triangle";
	
	
	/**
	 * 
	 * @param sidesMeasures: the measures of the triangle's sides.
	 */
	public IsoscelesRightTriangle(ArrayList<Double> sidesMeasures)
	{ 
		super(sidesMeasures); 
		super.polygonName = NAME;
	}

	
	/* ?????????
	@Override
	public Double calculateArea() {
		// TODO Auto-generated method stub
		return null;
	}*/
}

