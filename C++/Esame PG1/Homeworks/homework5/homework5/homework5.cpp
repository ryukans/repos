#include <iostream>
#include "Veicolo.h"
#include "Autovettura.h"
#include "Coda.h"

using namespace std;

int main()
{
	//Veicolo v("Berlina", "Mercedes");
	//Veicolo va;
	//cin >> v;
	//cout << v << endl;

	Auto a1("Berlina", "Alfa-Romeo", "Giulietta", 2);
	Auto a2("Spider", "Ferrari", "F430", 4);
	Auto a3("Coupé", "Maxda", "RX-8", 7);
	
	cout << a1 << endl << a2 << endl << a3 << endl;
	
	Coda c;

	c.append(&a1);
	c.append(&a2);
	c.append(&a3);

	//La coda è formata da oggetti di tipo Veicolo, quindi devo utilizzare un oggetto (puntatore) di tipo veicolo
	Veicolo* v; //Non posso utilizzare un oggetto di tipo Veiocolo ma solo un puntatore, perchè la classe è definita astratta !

	c.pop(v);
	cout << v << endl;
	

	return 0;
}
