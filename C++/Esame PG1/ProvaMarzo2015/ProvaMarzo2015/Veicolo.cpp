#include "Veicolo.h"


Veicolo::Veicolo() : nome(new char[1]), marca(new char[1])
{
	strcpy_s(nome, 1, "");
	strcpy_s(marca, 1, "");
}

Veicolo::Veicolo(const char* _nome, const char* _marca) : nome(new char[strlen(_nome) + 1]), marca(new char[strlen(_marca) + 1])
{
	strcpy_s(nome, strlen(_nome) + 1, _nome);
	strcpy_s(marca, strlen(_marca) + 1, _marca);
}

Veicolo::Veicolo(const Veicolo& V) : nome(new char[strlen(V.nome) + 1]), marca(new char[strlen(V.marca) + 1])
{
	strcpy_s(nome, strlen(V.nome) + 1, V.nome);
	strcpy_s(marca, strlen(V.marca) + 1, V.marca);
}

Veicolo::~Veicolo()
{
	delete[] nome;
	delete[] marca;
}

const Veicolo& Veicolo::operator=(const Veicolo& V)
{
	if (this != &V) {
		setNome(V.nome);
		setMarca(V.marca);
	}
	
	return *this;
}

bool Veicolo::operator==(const Veicolo& V) {
	return !strcmp(nome, V.nome) && !strcmp(marca, V.marca);
}

bool Veicolo::operator!=(const Veicolo& V) {
	return !(*this == V);
}

void Veicolo::setNome(const char* _nome)
{
	if (nome)
		delete[] nome;

	int len = strlen(_nome) + 1;
	nome = new char[len];
	strcpy_s(nome, len, _nome);
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
	char buffer[100] = "";

	in >> buffer;
	setNome(buffer);
	in >> buffer;
	setMarca(buffer);

	return in;
}

ostream& Veicolo::output(ostream& out) const {
	return out << nome << " " << marca;
}

char* Veicolo::toText() const
{
	char text[100] = "";
	strcat_s(text, nome);
	strcat_s(text, " ");
	strcat_s(text, marca);
	
	return text;
}

istream& operator>>(istream& in, Veicolo& V) {
	return V.input(in);
}

ostream& operator<<(ostream& out, const Veicolo& V) {
	return V.output(out);
}
