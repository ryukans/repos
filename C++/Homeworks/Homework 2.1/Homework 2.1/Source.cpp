#include "Header.h"



void create(Voce &v)
{
	v.descrizione = new char[maxlen];
	v.descrizione = (char*)"\0";
	v.chiave = 0;
}

void create(elencoVoci& e)
{
	for (size_t i = 0; i < maxsize; i++) create(e[i]);
}

void read(Voce &v)
{
	char* buffer = new char[maxlen];

	cin >> buffer;
	int size = strlen(buffer) + 1;
	if (size != 0) {
		v.descrizione = new char[size];  //instanzia
		v.descrizione = buffer;			//inizializza
	}

	cin >> v.chiave;
}

void read(elencoVoci &e, int dim) 
{
	for (int i = 0; i < dim; i++) read(e[i]);
}

void write(Voce v)
{
	cout << endl  << v.descrizione << '-' << v.chiave << endl;
}

void write(elencoVoci e, int dim)
{
	if (isEmpty(e, dim)) return;

	for (int i = 0; i < dim; i++) {
		cout << i + 1 << ')';
		write(e[i]);
	}
}

void copy(Voce v1, Voce v2)
{
	v1.chiave = v2.chiave;
	v1.descrizione = v2.descrizione;
}

bool equal(Voce v1, Voce v2)
{
	return (v1.chiave == v2.chiave && strcmp(v1.descrizione, v2.descrizione)==0);
}


bool greaterThan(Voce v1, Voce v2)
{
	return (v1.chiave > v2.chiave);
}

void destroy(Voce& v) 
{
	delete[] v.descrizione;

	v.chiave = 0;
	v.descrizione = (char*)"";
}

void in(Voce v, elencoVoci e, int dim, int &pos)
{
	int i = 0;
	while (i < dim && !equal(v, e[i++]));

	pos = i;
}

void sort(elencoVoci &e, int dim)
{
	if (isSorted(e, dim)) return;

	for (size_t i = 0; i < dim; i++) {
		for (size_t j = 0; j < dim; j++) {
			if (e[i].chiave < e[j].chiave) {
				swap(e[i], e[j]);
			}
		}
	} 
}


void swap(Voce &a, Voce &b)
{
	Voce tmp;

	tmp = a;
	a = b;
	b = tmp;
}


bool isFull(elencoVoci e, int dim)
{
	if (isEmpty(e, dim)) return false;

	Voce voceVuota;
	create(voceVuota);

	int i = 0;
	while (i < dim && !equal(e[i++], voceVuota));

	destroy(voceVuota);

	return i == dim ? true : false;
}

bool isEmpty(elencoVoci e, int dim)
{
	Voce voceVuota;
	create(voceVuota);

	int i = 0;
	while (i < dim && equal(e[i++], voceVuota));

	destroy(voceVuota);

	return i == dim ? true : false;
}


void insert(Voce v, elencoVoci& e, int dim)
{
	if (isFull(e, dim)) return;

	Voce voceVuota;
	create(voceVuota);

	int i = 0;
	while (i < dim && !equal(e[i], voceVuota))
		i++;

	e[i] = v;

	destroy(voceVuota);
}

void insertOrd(Voce v, elencoVoci& e, int dim)
{
	if (isFull(e, dim)) return;

	if (!isSorted(e, dim)) 
		sort(e, dim);

	int i = 0;
	while (i < dim && greaterThan(v, e[i]))
		i++;

	e[i] = v;
}

void remove(Voce v, elencoVoci& e, int dim)
{
	if (isEmpty(e, dim)) return;

	Voce voceVuota;
	create(voceVuota);

	int i = 0;
	while (i < dim && !equal(v, e[i]))
		i++;

	e[i] = voceVuota;

	//destroy(voceVuota);
 }

bool isSorted(elencoVoci e, int dim)
{
	if (isEmpty(e, dim)) return true;

	int i = 0;
	while (i < dim && !greaterThan(e[i], e[i + 1]))
		i++;

	return (i == dim) ? true : false;
}