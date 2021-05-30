#pragma once
#include "Packet.h"

#define __this (*this) // use accordingly

typedef Packet P;
using std::out_of_range;
using std::cerr;

class Vector
{
	friend istream& operator>>(istream&, Vector&);
	friend ostream& operator<<(ostream&, const Vector&);

private:
	P* v;
	int size;

public:
	Vector(const int = 0);
	Vector(const Vector&);
	~Vector();

	const Vector& operator=(const Vector&);
	const P& operator[](const int) const;
	P& operator[](const int);
	bool operator==(const Vector&) const;
	bool operator!=(const Vector&) const;
	
	const P& at(const int) const throw(out_of_range);
	P& at(const int) throw(out_of_range);
	int getSize() const { return size; }
	const Vector& getVector() const { return *this; }
	
	void removeHeavy();
	void removeHeavy(const int);
};

