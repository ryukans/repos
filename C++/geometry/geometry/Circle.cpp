#include "Circle.h"

Circle::Circle(double r, int a, int b) : Point(a, b)
{
	setRadius(r);
}

void Circle::setRadius(double radius)
{
	if (radius > 0)
		(*this).radius = radius;
}

double Circle::area() const
{
	return 3.14*(radius*radius);
}
