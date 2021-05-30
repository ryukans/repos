#include "Cylinder.h"

Cylinder::Cylinder(double h, double r, int x, int y) : Circle(r, x, y)
{
	setHeight(h);
}

void Cylinder::setHeight(double height)
{
	if (height > 0)
		this->height = height;
}

double Cylinder::area() const
{
	double r = getRadius();

	return (2 * 3.14 * height) + (2 * 3.14 * (r * r));
}

double Cylinder::volume() const
{
	double r = getRadius();

	return height * 3.14 * (r * r);;
}
