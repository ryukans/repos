package it.Geometry.subclasses.quadrilaterals;

import java.util.ArrayList;

public class Trapezoid extends Quadrilateral
{
	private final String DEFAULT_NAME = "Trapezoid";
	
	public Trapezoid(ArrayList<Double> sides)
	{ 
		super(sides);
		polygonName = DEFAULT_NAME;
	}
	
	public Trapezoid()
	{}
	
	@Override
	public Double calculateArea()
	{ return 0.0; } //TODO: Complete this method
}
