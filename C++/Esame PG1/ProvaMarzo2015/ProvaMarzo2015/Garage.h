#pragma once
#include <iostream>
#include "Veicolo.h"

typedef Veicolo V;

using std::istream;
using std::ostream;

class Garage
{
	friend istream& operator>>(istream&, Garage&);
	friend ostream& operator<<(ostream&, const Garage&);

private:
	static const int N = 20;
	V veicoli[N];
	int testa;
	int coda;
	int nelem;

public:
	Garage() : testa(0), coda(0), nelem(0) {};

	int inserisci(const V&);
	void rimuovi(V&);
	void rimuovi(V&, const int);

};

