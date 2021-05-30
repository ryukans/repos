/**
 * @author  claudiopisa
 * @author
 */

package it.claudiopisa.Geometry;

public class Polygon 
{
	/**
	 * <pre>
	 * The array now cannot be used because its size 
	 * it's not declared, it will be declared by
	 * the Polygon's sublasses.
	 * e.g.:
	 * For the <code>Polygon</code>'s subclass <code>Quadrilateral</code>, the size will be equal to 4
	 * or for the <code>Polygon</code>'s subclass <code>Triangle</code>, the size will be equal to 3.
	 * </pre>
	 */
	protected double[] measures; 
	
	protected double area()
	{
		/* TODO
		 * - Shoelace formula¹ -
		 * It determines the area of a simple polygon whose vertices 
		 * are described by their Cartesian coordinates in the plane
		 */ 
		return 0; 
	}
}


/*
 * ¹Also known as Guass formula.
 * see: https://en.wikipedia.org/wiki/Shoelace_formula
 */