package it.Geometry.test;

import java.util.ArrayList;
import it.Geometry.subclasses.triangles.*;
import it.Geometry.subclasses.quadrilaterals.*;


/**
 * 
 * @author Claudio Pisa
 *
 */
public class TestClass
{
	/**
	 * 
	 * @param args
	 */
	public static void main(String[] args)
	{
		ArrayList<Double> sidesMeasures = new ArrayList<Double>();
		
		
		/* Triangle */
		
		sidesMeasures.add(10.0);
		sidesMeasures.add(8.0);
		sidesMeasures.add(6.12);
	
		Triangle trn = new Triangle(sidesMeasures);
		trn.printInfo(trn);

		
		/* Isosceles */
		
		sidesMeasures.clear();
		sidesMeasures.add(10.0);
		sidesMeasures.add(10.0);
		sidesMeasures.add(7.0);
		
		Isosceles iso = new Isosceles(sidesMeasures);
		iso.printInfo(iso);

		
		/* Equilateral */
		
		sidesMeasures.clear();
		sidesMeasures.add(12.0);
		sidesMeasures.add(12.0);
		sidesMeasures.add(12.0);
		
		Equilateral eql = new Equilateral(sidesMeasures);
		eql.printInfo(eql);

		
		/* Right triangle */
		
		sidesMeasures.clear();
		sidesMeasures.add(6.5);
		sidesMeasures.add(9.4);
		sidesMeasures.add(10.3);
		
		RightTriangle rghTrn = new RightTriangle(sidesMeasures);
		rghTrn.printInfo(rghTrn);
		
		
		/* Isosceles right triangle */
		
		sidesMeasures.clear();
		sidesMeasures.add(7.15);
		sidesMeasures.add(7.15);
		sidesMeasures.add(10.0);
		
		IsoscelesRightTriangle isoRghTrn = new IsoscelesRightTriangle(sidesMeasures);
		isoRghTrn.printInfo(isoRghTrn);
		
		
		/* non valid triangle */

		sidesMeasures.clear();
		sidesMeasures.add(1.5);
		sidesMeasures.add(2.14);
		sidesMeasures.add(9.03);
		
		Triangle nonValidTriangle = new Triangle(sidesMeasures);
		nonValidTriangle.printInfo("Non valid Triangle", nonValidTriangle);

		
		/* without specifing the measures */
		
		sidesMeasures.clear();

		Triangle nonSpecifiedTriangle = new Triangle(sidesMeasures);
		nonSpecifiedTriangle.printInfo("Non specified triangle", nonSpecifiedTriangle);
		
		
		/* non valid equilateral */
		
		sidesMeasures.clear();
		sidesMeasures.add(55.12);
		sidesMeasures.add(55.12);
		sidesMeasures.add(50.12);
		
		Equilateral nonValidEquilateral = new Equilateral(sidesMeasures);
		nonValidEquilateral.printInfo("Non valid equilateral", nonValidEquilateral);
		
		/* Square */
		
		sidesMeasures.clear();
		sidesMeasures.add(10.8);
		sidesMeasures.add(10.8);
		sidesMeasures.add(10.8);
		sidesMeasures.add(10.8);
		
		Square sqr = new Square(sidesMeasures);
		
		sqr.printInfo(sqr);
		
		System.exit(0);
	}
}

