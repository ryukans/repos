#include "Veicolo.h"
#include <cstring>


void Veicolo::setNomeTipo(const char* _tipo)
{
	const int len = strlen(_tipo) + 1;
	
	delete[] nomeTipo;
	nomeTipo = new char[len];
	strcpy_s(nomeTipo, len, _tipo);
}

void Veicolo::setMarca(const char* _marca)
{
	const int len = strlen(_marca) + 1;

	delete[] marca;
	marca = new char[len];
	strcpy_s(marca, len, _marca);
}

istream& Veicolo::input(istream& in)
{
	char buffer[100] = "";

	in.getline(buffer, 100);
	setNomeTipo(buffer);

	in.ignore();

	in.getline(buffer, 100);
	setMarca(buffer);

	return in;
}

ostream& Veicolo::output(ostream& out) const {
	return out << nomeTipo << '\t' << marca;
}

Veicolo::Veicolo() : nomeTipo(new char[1]), marca(new char[1])
{
	strcpy_s(nomeTipo, 1, "");
	strcpy_s(marca, 1, "");
}

Veicolo::Veicolo(const char* nomeTipo, const char* marca)
{
	setNomeTipo(nomeTipo);
	setMarca(marca);
}

Veicolo::Veicolo(const Veicolo& V)
{
	setNomeTipo(V.nomeTipo);
	setMarca(V.marca);
}

Veicolo::~Veicolo()
{
	delete[] nomeTipo;
	delete[] marca;
}

const Veicolo& Veicolo::operator=(const Veicolo& V)
{
	if (this != &V) {
		setNomeTipo(V.nomeTipo);
		setMarca(V.marca);
	}

	return *this;
}

bool Veicolo::operator==(const Veicolo& V) const {
	return !strcmp(nomeTipo, V.nomeTipo) && !strcmp(marca, V.marca);
}

bool Veicolo::operator!=(const Veicolo& V) const {
	return !(*this == V);
}

