#pragma once
#include "Circle.h"

class Cylinder : public Circle
{
	double height;

public:
	Cylinder(double h = 0.0, double r = 0.0, int x = 0, int y = 0);
	void setHeight(double);
	double getHeight() const { return height; }
	virtual double area() const;
	virtual double volume() const;
	virtual void printShapeName() const
	{
		cout << "Cylinder: \n";
	}
	virtual void print() const
	{
		printShapeName();
		cout << "Radius: " << getRadius() 
				<< " Area: " << area() 
					<< " Volume: " << volume() 
						<< endl;
	}
};

