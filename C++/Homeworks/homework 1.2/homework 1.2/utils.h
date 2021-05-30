#include <iostream>	
#include <string>

using namespace std;

const int dim = 2;

struct Calciatore {
	string nome;
	string cognome;
	string squadra;
	int goal;
};

typedef Calciatore elencoCalciatori[dim];

void setCalciatore(
	Calciatore &
);

void getCalciatore(
	Calciatore
);

void setGoal(
	Calciatore &
);

int getGoal(
	Calciatore
);

bool uguali(
	Calciatore,
	Calciatore
);

void setElenco(
	elencoCalciatori &,
	int dimensioneTotale,
	int & numeroElementi
);

bool setElenco(
	Calciatore &,
	elencoCalciatori,
	int dimensioneTotale,
	int & numeroElementi
);

void getElenco(
	elencoCalciatori,
	int numeroElementi
);


void verificaElemento(
	Calciatore, 
	elencoCalciatori,
	int numeroElementi,
	int & posizione
);

void riordinaElenco(
	elencoCalciatori,
	int numeroElementi
);

void copiaElenco(
	elencoCalciatori originale,
	elencoCalciatori copia,
	int numeroElementi
);