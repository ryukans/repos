package it.Geometry.subclasses.quadrilaterals;

import java.util.ArrayList;

public class Square extends Rectangle
{	
	private final String DEFAULT_NAME = "Square";
	
	public Square(ArrayList<Double> sidesMeasures)
	{ 
		super(sidesMeasures);
		super.sidesMeasures.clear();
		super.sidesMeasures.add(0, sidesMeasures.get(0));
		polygonName = DEFAULT_NAME;
	}
	
	
	public boolean isASquare()
	{ return false; } //TODO: complete
	
	
	@Override
	public Double calculatePerimeter()
	{ return sidesMeasures.get(0)*4; }
	
	@Override
	public Double calculateArea()
	{ return sidesMeasures.get(0)*sidesMeasures.get(0); }
	
	/*
	@Override
	public Double calculateArea()
	{ return Math.pow(sidesMeasures.get(0), 2); }*/
}

