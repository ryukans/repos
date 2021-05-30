/**
 * @author  claudiopisa
 * @author
 * @see it.claudiopisa.Geometry.Polygon
 */

package it.claudiopisa.Geometry;

public class Quadrilateral extends Polygon
{
	private final int NUM_SIDES = 4;
	
	/**
	 * @param b1 (Base)
	 * @param b2 (Base)
	 * @param s1 (Side)
	 * @param s2 (Side)
	 */
	public Quadrilateral(double b1, double b2, double s1, double s2)
	{
		this.measures = new double[NUM_SIDES];
		this.measures[0] = b1;
		this.measures[1] = b2;
		this.measures[2] = s1;
		this.measures[3] = s2; // This side is never used
	}
	
	/** 
	 * <pre>
	 * @see it.claudiopisa.Geometry.Polygon#area()
	 * 
	 * Since that the <bold>area</bold> method in Polygon is not completed, there will be
	 * used this <bold>area</bold> method (the original is overwritten) with the following formula:
	 * <i>(B + b) * h / 2</i>
	 * </pre>
	 */
	public double area()
	{ return (measures[0] + measures[1]) * measures[2] / 2; }
}

	/* NOT USED CODE. DO NOT DELETE */

	//public double b1, b2, s1, s2;

	/*
	public Quadrilateral(double b1, double b2, double s1, double s2)
	{
		this.b1 = b1;
		this.b2 = b2;
		this.s1 = s1;
		this.s2 = s2;
	}
	
	
	public Quadrilateral(int b1, int b2, int s1, int s2)
	{
		this.b1 = b1;
		this.b2 = b2;
		this.s1 = s1;
		this.s2 = s2;
	}*/


	/*public Quadrilateral(int numSides, int base1, int base2, int side1, int side2)
	{
		this.intMeasures = new int[numSides];
		this.intMeasures[0] = base1;
		this.intMeasures[1] = base2;
		this.intMeasures[2] = side1;
		this.intMeasures[3] = side2;
	}*/

	/*
	public double area()
	{ return (b1 + b2) * s1 / 2; } */

