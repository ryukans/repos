#include "Vector.h"

Vector::Vector(const int _size) : size(_size) {
	v = new P[size];
}

Vector::Vector(const Vector& _v) : size(_v.size)
{
	v = new P[size];
	for (int i = 0; i < size; i++)
		v[i] = _v[i];
}

const Vector& Vector::operator=(const Vector& _v)
{
	if (this != &_v)	{
		delete[] v;
		size = _v.size;
		v = new P[size];

		for (int i = 0; i < size; i++)
			v[i] = _v[i];
	}

	return *this;
}

const P& Vector::operator[](const int i) const 
{
	const P* tmp;
	try {
		tmp = &at(i);
	}
	catch (out_of_range exc) {
		cerr << exc.what() << endl;
		tmp = new P;
	}
	return *tmp;
}

P& Vector::operator[](const int i) 
{
	P* tmp;
	try {
		tmp = &at(i);
	}
	catch (out_of_range exc) {
		cerr << exc.what() << endl;
		tmp = new P;
	}
	return *tmp;
}

bool Vector::operator==(const Vector& _v) const
{
	if (size != _v.size) return false;

	int i = 0;
	while (i < size) {
		if (v[i] == _v[i++])
			return true;
	}

	return false;
}

bool Vector::operator!=(const Vector& other) const {
	return !(*this == other);
}

const P& Vector::at(const int i) const throw(out_of_range)
{
	if (i < 0 || i > size)
		throw out_of_range("Index out of range\n");

	return v[i];
}

P& Vector::at(const int i) throw(out_of_range) 
{
	if (i < 0 || i > size)
		throw out_of_range("Index out of range\n");

	return v[i];
}

void Vector::removeHeavy()
{
	int i = 0;
	while (i < size && v[i].getWeight() < 0.5f)
		++i;

	for (int j = i; j < size-1; j++) // si ferma al penultimo elemento
		v[j] = v[j + 1];

	//v[j-1] = ?; Il penultimo elemento non viene gestito
	--size; 
}

void Vector::removeHeavy(const int pos)
{
	if (pos < 0)
		return;

	for (int i = pos; i < size - 1; i++)
		v[i] = v[i+1];

	--size;
}


Vector::~Vector() {
	delete[] v;
}

istream& operator>>(istream& in, Vector& _this)
{
	// non ho bisogno di delete[] _this.v; perché non è un vettore di puntatori

	for (int i = 0; i < _this.size; i++)
		in >> _this[i];

	return in;
}

ostream& operator<<(ostream& out, const Vector& _this)
{
	for (int i = 0; i < _this.size; i++)
		out << _this[i] << endl;

	return out;
}
