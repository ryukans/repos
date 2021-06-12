#include "Garage.h"

int Garage::inserisci(const V& veicolo)
{
	if (nelem == N)
		return -coda;

	veicoli[coda] = veicolo;
	coda = (coda + 1) % N;
	++nelem;

	return (coda-1);
}

void Garage::rimuovi(V& veicolo)
{
	if (testa == coda)
		return;

	veicolo = veicoli[testa];
	testa = (testa + 1) % N;
	--nelem;
}

void Garage::rimuovi(V& veicolo, const int pos)
{
	if (testa == coda || pos <= 0 || pos > nelem)
		return;

	veicolo = veicoli[pos-1];
	//veicoli[pos-1].setNome("");
	//veicoli[pos-1].setMarca("");
	//testa = (testa + 1) % N;

	for (int i = pos-1; i < coda; i++) {
		veicoli[i] = veicoli[i+1];
	}
	--coda;
	--nelem;
}

istream& operator>>(istream& in, Garage& G)
{
	return in;
}

ostream& operator<<(ostream& out, const Garage& G)
{

	for (int i = G.testa; i != G.coda; i++)
	{
		out << G.veicoli[i] << " | ";
	}
	out << std::endl;

	return out;
}
