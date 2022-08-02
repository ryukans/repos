#include "Garage.h"


int Garage::inserisci(const V& veicolo)
{
	if (nelem == SIZE)
		return -1;

	garage[nelem++] = veicolo;

	return nelem;
}

void Garage::rimuovi(const int pos)
{
	if (pos < 0 || pos > nelem)
		return;

	for (int i = pos; i < nelem - 1; i++)
		garage[i] = garage[i+1];

	--nelem;
}

ostream& operator<<(ostream& out, const Garage& _this)
{
	out << "Garage:" << std::endl;

	for (int i = 0; i < _this.nelem; i++){
		out << " | " << *_this.garage[i] << " | \n";
}
		

	return out << std::endl;
}
