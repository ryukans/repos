#pragma once
#include "Shape.h"

class Point : public Shape
{
	int x, y;
public:
	Point(int x = 0, int y = 0) { setPoint(x, y); }
	void setPoint(int, int);
	int getX() const { return x; }
	int getY() const { return y; }
	virtual void printShapeName() const
	{
		std::cout << "Point: \n";
	}
	virtual void print() const
	{
		printShapeName();
		cout << x << ' ' << y << endl;
	}
};

