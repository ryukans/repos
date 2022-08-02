#include "Moto.h"


istream& Moto::input(istream& in)
{
	Veicolo::input(in);

	char buffer[100] = "";
	in.getline(buffer, 100);
	setTipo(buffer);
	
	return in;
}

ostream& Moto::output(ostream& out) const
{
	Veicolo::output(out);

	return out << " " << tipo;
}

Moto::Moto() : Veicolo(), tipo(new char[1]) {
	strcpy_s(tipo, 1, "");
}

Moto::Moto(const char* nomeTipo, const char* marca, const char* tipo) : Veicolo(nomeTipo, marca) {
	setTipo(tipo);
}

Moto::Moto(const Moto& M) : Veicolo(M) {
	setTipo(tipo);
}

const Moto& Moto::operator=(const Moto& M)
{
	if (this != &M) {
		Veicolo::operator=(M);
		setTipo(M.tipo);
	}
	
	return *this;
}

bool Moto::operator==(const Moto& M) const {
	return Veicolo::operator==(M) && !strcmp(tipo, M.tipo);
}

bool Moto::operator!=(const Moto& M) const {
	return !(*this == M);
}

void Moto::setTipo(const char* _tipo)
{
	const int len = strlen(_tipo) + 1;

	delete[] tipo;
	tipo = new char[len];
	strcpy_s(tipo, len, _tipo);
}
