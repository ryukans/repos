#pragma once
#include "Veicolo.h"

typedef Veicolo* V;

class Garage
{
	friend ostream& operator<<(ostream&, const Garage&);

private:
	static const int SIZE = 20;
	V garage[SIZE];
	int nelem;

public:
	Garage() : nelem(0), garage() {};

	int inserisci(const V&);
	void rimuovi(const int);
	


};
