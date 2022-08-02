#include <iostream>
#include <stdlib.h>
#include <string>


using namespace std;
const int maxsize = 100;
const int maxlen = 10;

struct Voce
{
	int chiave;
	char* descrizione;
};

typedef Voce elencoVoci[maxsize];

void create(
	Voce &
);

void create(
	elencoVoci&
);

void read(
	Voce &
);

void read(
	elencoVoci &,
	int dimensione
);

void write(
	Voce
);

void write(
	elencoVoci,
	int dimensione
);

void copy(
	Voce copia,
	Voce originale
);

bool equal(
	Voce,
	Voce
);

bool greaterThan(
	Voce,
	Voce
);

void in(
	Voce,
	elencoVoci,
	int dimensione,
	int &posizione
);

void sort(
	elencoVoci &,
	int dimensione
);

bool isFull(
	elencoVoci,
	int dimensione
);

bool isEmpty(
	elencoVoci,
	int dimensione
);

void insert(
	Voce,
	elencoVoci&,
	int dimensione
);

void remove(
	Voce,
	elencoVoci&,
	int dimensione
);

void insertOrd(
	Voce,
	elencoVoci&,
	int dimensione
);

bool isSorted(
	elencoVoci,
	int dimensione
);