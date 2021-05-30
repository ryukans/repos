#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Shape
{
public:
	virtual double area() const { return 0.0; }
	virtual double volume() const { return 0.0; }
	virtual void printShapeName() const = 0;
	virtual void print() const = 0;
};

