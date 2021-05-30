/**
 * @author  claudiopisa
 * @author
 * @see it.claudiopisa.Geometry.Polygon
 * @see it.claudiopisa.Geometry.Quadrilateral
 * @see it.claudiopisa.Geometry.Rectangle
 * @see it.claudiopisa.Geometry.Square
 */

package it.claudiopisa.Geometry;

public class Test 
{
	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		/** 
		 * <p>
		 * Here is passed the <i>lenght</i> of all four sides 
		 * </p>
		 */
		Square sqr0 = new Square(7.12);
		Square sqr1 = new Square(4);

		System.out.println("Square's area>: " + sqr0.area() + " cm^2\n");
		System.out.println("Square's area>: " + (int) sqr1.area() + " cm^2\n");

		
		System.out.println("-\n");
		
		
		/**
		 * <p>
		 * Here are passed respectively the lenght of the <i>bases</i> and the <i>height</i>
		 * </p>
		 */
		Rectangle rct0 = new Rectangle(12.6, 7); 
		Rectangle rct1 = new Rectangle(20, 31);
		
		System.out.println("Rectangle's area>: " + rct0.area() + " cm^2\n");
		System.out.println("Rectangle's area>: " + (int) rct1.area() + " cm^2\n");
		
		System.exit(0);
	}
}
