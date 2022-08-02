#include "Header.h"

int main()
{
	const int dim = 3;
	int pos = -1;
	Voce v, v2;
	elencoVoci e, e2;
	create(v);
	create(v2);
	create(e);
	create(e2);


	cout << "Inserisci voce" << endl;
	read(v);
	
	cout << "Inserisci elenco" << endl;
	read(e, dim);
	cout << "Elenco" << endl;
	write(e, dim);
	
	remove(v, e, dim);
	write(e, dim);

	read(v2);
	insertOrd(v2, e, dim);
	write(e, dim);
	

	//isSorted(e, dim) ? cout << "Elenco ordinato" << endl : cout << "Elenco non ordinato" << endl;

	//cout << "Elenco ordinato" << endl;
	//sort(e, dim);
	//write(e, dim);
	
	isFull(e, dim)  ? cout << "Elenco pieno" << endl : cout << "Elenco non pieno" << endl;
	isEmpty(e2, dim) ? cout << "Elenco vuoto" << endl : cout << "Elenco non vuoto" << endl;
	
	//in(v, e, dim, pos);
	//cout << endl << "Posizione: " << pos << endl;

	return 0;
}
