package it.Geometry.subclasses.triangles;

import java.util.ArrayList;
import java.util.Iterator;
import it.Geometry.superclasses.Polygon;


/**
 * 
 * @author Claudio Pisa
 * 
 */
public class Triangle extends Polygon // scalene triangle
{
	private final String NAME = "Scanele triangle";
	private final int NUMBER_OF_SIDES = 3, NUMBER_OF_ANGLES = 3;
	
	/**
	 * 
	 * @param sidesMeasures: the measures of the triangle's sides.
	 */
	public Triangle(ArrayList<Double> sidesMeasures)
	{
		if(sidesMeasures.isEmpty())
			System.out.println("Error: measures are not specified !");
		else{
			for(int i = 0; i < NUMBER_OF_SIDES; ++i) // creating triangle
				super.sidesMeasures.add(i, sidesMeasures.get(i));
		
			if(!isATriangle()){
				System.out.println("Error: triangle is not valid !\nwrong measures");
				super.sidesMeasures.clear();
			}
			else{
				super.polygonName = NAME;
				super.numberOfSides = NUMBER_OF_SIDES;
				super.numberOfAngles = NUMBER_OF_ANGLES;
			}
		}
	}
	
	/**
	 * <pre><strong>
	 * a < b + c  V  a > b - c
	 * b < a + c  V  b > a - c
	 * c < a + b  V  c > a - b
	 * </strong></pre>
	 * 
	 * 
	 * @return <pre>
	 * <b>{@code true}</b> if the measures are correct;
	 * <b>{@code false}</b> otherwise.
	 */
	private boolean isATriangle()
	{
		Double	a = sidesMeasures.get(0), 
				b = sidesMeasures.get(1), 
				c = sidesMeasures.get(2);
		
		if((a < (b + c) && a > (b - c))
		&& (b < (a + c) && b > (a - c))
		&& (c < (a + b) && c > (a - b)))
			return true;
		
		return false;
	}
	
	
	/**
	 * <strong><em>Eron's formula</em></strong>
	 * 
	 * @return Triangle area.
	 * @see it.Geometry.superclasses.Polygon#calculateArea(){@link #calculateArea()}
	 */
	@Override
	public Double calculateArea()
	{
		Iterator<Double> index;	/* needed to loop though the array list */
		Double	area,			/* area */
				sp,				/* semiperimeter */
				rad;			/* radicand */
		
		rad = sp = calculatePerimeter()/2;
		index = sidesMeasures.iterator();
		while(index.hasNext())
			rad *= (sp - (Double) index.next());
		
		area = rad;
		
		return Math.sqrt(area);
	}
}

