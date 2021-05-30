package it.Geometry.subclasses.quadrilaterals;

import java.util.ArrayList;

public class Rectangle extends Trapezoid
{
	private final String DEFAULT_NAME = "Rectangle";
	
	public Rectangle(ArrayList<Double> sidesMeasures)
	{ 
		super(sidesMeasures); 
		polygonName = DEFAULT_NAME;
	}
}

