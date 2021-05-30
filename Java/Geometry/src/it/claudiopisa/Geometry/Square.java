/**
 * @author  claudiopisa
 * @author
 * @see it.claudiopisa.Geometry.Quadrilateral
 */

package it.claudiopisa.Geometry;

public class Square extends Quadrilateral
{
	/**
	 * <pre>
	 * @param sidelenght
	 * 
	 * Only one value is passed because just one is needed
	 * since <strong>all the sides</strong> of the square measure equal</strong>
	 * </pre>
	 */
	public Square(double sidesLenght)
	{ super(sidesLenght, sidesLenght, sidesLenght, sidesLenght); }
	
	/* A SECOND CONSTRUCTOR IS NOT USEFUL, IT COULD BE DELETED
	 * public Square(int sidesLenght)
	 * { super(sidesLenght, sidesLenght, sidesLenght, sidesLenght); } 
	 */
}

