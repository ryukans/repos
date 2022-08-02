#include "Garage.h"
#include "Veicolo.h"
#include "Auto.h"
#include "Moto.h"

using namespace std;

int main()
{
	Garage g;
	Veicolo* v1 = new Veicolo("Spider", "Ferrari");
	Veicolo v2("Berlina", "Alfa-Romeo");
	Veicolo* v3 = new Veicolo("Coupé", "Mazda");
	//Veicolo* a1 = new Auto("Spider", "Ferrari", "Benzina");
	Auto a1("Spider", "Ferrari", "Benzina");

	g.inserisci(&a1);

	g.inserisci(&v2);
	g.inserisci(v3);

	cout << g;

	g.rimuovi(1);

	cout << g << endl;


	return 0;
}
