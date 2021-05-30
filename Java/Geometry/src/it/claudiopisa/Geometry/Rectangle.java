/**
 * @author  claudiopisa
 * @author
 * @see it.claudiopisa.Geometry.Quadrilateral
 */

package it.claudiopisa.Geometry;

public class Rectangle extends Quadrilateral
{	
	/**
	 * <pre>
	 * Only two values are passed: 
	 * @param bases: lenght of both bases
	 * @param sides: lenght of both sides
	 * 
	 * <strong>(rectangle has alternate sides equal)</strong>
	 * </pre>
	 */
	public Rectangle(double bases, double sides)
	{ super(bases, bases, sides, sides); }

	/* A SECOND CONSTRUCTOR IS NOT USEFUL, IT COULD BE DELETED
	 * public Rectangle(int bases, int sides)
	 * { super(bases, bases, sides, sides); } 
	 */
}
