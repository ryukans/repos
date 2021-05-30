#include <iostream>
#include "Shape.h"
#include "Point.h"
#include "Circle.h"
#include "Cylinder.h"

void virtualViaPointer(const Shape* baseClassPtr);
void virtualViaReference(const Shape& baseClassRef);

int main()
{
	Point point(7, 11);
	Circle circle(3.5, 22, 8);
	Cylinder cylinder(10, 3.3, 10, 10);

	point.printShapeName(); // binding statico
	point.print();
	circle.printShapeName(); // binding statico
	circle.print();
	cylinder.printShapeName(); // binding statico
	cylinder.print();

	Shape* shapes[3]{}; // array di puntatori ( alla classe BASE
	shapes[0] = &point;
	shapes[1] = &circle;
	shapes[2] = &cylinder;

	cout << "binding dinamico via puntatori alla classe base\n";
	for (int i = 0; i < 3; i++)
		virtualViaPointer(shapes[i]);

	cout << "\nChiamata alle funzioni virtuali:\n ";
	cout << "binding dinamico via riferimenti alla classe base\n";

	for (int j = 0; j < 3; j++)
		virtualViaReference(*shapes[j]);


	return 0;
}

void virtualViaPointer(const Shape* baseClassPtr) {
	baseClassPtr->printShapeName();
	baseClassPtr->print();
	cout << "\nArea = " << baseClassPtr->area() << "\nVolume = "
		<< baseClassPtr->volume() << "\n\n";
}

void virtualViaReference(const Shape& baseClassRef) {
	baseClassRef.printShapeName();
	baseClassRef.print();
	cout << "\nArea = " << baseClassRef.area() << "\nVolume = "
		<< baseClassRef.volume() << "\n\n";
}
