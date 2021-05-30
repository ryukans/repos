package it.Geometry.subclasses.quadrilaterals;

import java.util.ArrayList;
import it.Geometry.superclasses.Polygon;

public abstract class Quadrilateral extends Polygon
{
	private final int NUM_OF_SIDES = 4, NUM_OF_ANGLES = 4;

	public Quadrilateral(ArrayList<Double> sidesMeasures)
	{
		for(int i = 0; i < NUM_OF_SIDES; ++i) //creating quadrilateral
			super.sidesMeasures.add(i, sidesMeasures.get(i));
		
		numberOfSides = NUM_OF_SIDES;
		numberOfAngles = NUM_OF_ANGLES;
	}
	
	public Quadrilateral()
	{}
}

