#pragma once
#include "Point.h"

class Circle :public Point
{
	double radius;
public:
	Circle(double r = 0.0, int a = 0, int b = 0);
	void setRadius(double);
	double getRadius() const { return radius; }
	virtual double area() const;
	virtual void printShapeName() const
	{
		cout << "Circle: \n";
	}
	virtual void print() const
	{
		printShapeName();
		cout << "Radius: " << radius << " Area: " << area() << endl;
	}
};

