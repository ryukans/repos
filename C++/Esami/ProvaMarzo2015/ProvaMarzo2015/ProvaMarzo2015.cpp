#include <iostream>
#include "Veicolo.h"
#include "Garage.h"

using namespace std;

int main()
{
	Garage g;
	Veicolo v1("Spider", "Ferrari");
	Veicolo v2("Berlina", "Alfa-Romeo");
	Veicolo v3("Coupé", "Mazda");
	Veicolo v4;

	g.inserisci(v1);
	g.inserisci(v2);
	g.inserisci(v3);

	cout << g << endl;

	g.rimuovi(v4, 2);

	cout << g << endl;
	cout << v4;

	return 0;
}
