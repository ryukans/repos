#include "Veicolo.h"


Veicolo::Veicolo() : tipo(new char[1]), marca(new char[1])
{
	strcpy_s(tipo, 1, "");
	strcpy_s(marca, 1, "");
}

Veicolo::Veicolo(const char* _tipo, const char* _marca)
{
	setTipo(_tipo);
	setMarca(_marca);
}

Veicolo::Veicolo(const Veicolo& V)
{
	setTipo(V.tipo);
	setMarca(V.marca);
}

Veicolo::~Veicolo()
{
	delete[] tipo;
	delete[] marca;
}

const Veicolo& Veicolo::operator=(const Veicolo& V)
{
	if (this != &V) {
		setTipo(V.tipo);
		setMarca(V.marca);
	}
	return *this;
}

bool Veicolo::operator==(const Veicolo& V) const {
	return !strcmp(tipo, V.tipo) && !strcmp(marca, V.marca);
}

bool Veicolo::operator!=(const Veicolo& V) const {
	return !(*this == V);
}


void Veicolo::setTipo(const char* _tipo)
{
	if (tipo)
		delete[] tipo;

	int len = strlen(_tipo) + 1;

	tipo = new char[len];
	strcpy_s(tipo, len, _tipo);
}

void Veicolo::setMarca(const char* _marca)
{
	if (marca)
		delete[] marca;

	int len = strlen(_marca) + 1;

	marca = new char[len];
	strcpy_s(marca, len, _marca);

}

istream& Veicolo::input(istream& in)
{
	char buffer[100];

	in >> buffer;
	setTipo(buffer);
	in >> buffer;
	setMarca(buffer);

	return in;
}

ostream& Veicolo::output(ostream& out) const {
	return out << tipo << " - " << marca;
}

istream& operator>>(istream& in, Veicolo& V){
	return V.input(in);
}

ostream& operator<<(ostream& out, const Veicolo& V) {
	return V.output(out);
}

