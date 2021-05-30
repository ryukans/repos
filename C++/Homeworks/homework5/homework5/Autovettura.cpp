#include "Autovettura.h"


Auto::Auto()
	: Veicolo(), modello(new char[1]), classe(0)
{
	strcpy_s(modello, 1, "");
}

Auto::Auto(const char* tipo, const char* marca, const char* _modello, const int _classe)
	: Veicolo(tipo, marca)
{
	setModello(_modello);
	setClasse(_classe);
}

/*
Auto::Auto(const char* _modello, const int _classe, const Veicolo& V)
	: Veicolo(V)
{
	setModello(_modello);
	setClasse(_classe);
}*/

Auto::Auto(const Auto& A) 
	: Veicolo(A)
{
	setModello(A.modello);
	classe = A.classe; // non c'è bisogno di utilizzare setClasse
}

Auto::~Auto() {
	delete[] modello;
}

const Auto& Auto::operator=(const Auto& A)
{
	if (this != &A) {
		Veicolo::operator=(A);
		setModello(A.modello);
		setClasse(A.classe);
	}
	return *this;
}

bool Auto::operator==(const Auto& A) const {
	return Veicolo::operator==(A) && !strcmp(modello, A.modello) && (classe == A.classe);
}

bool Auto::operator!=(const Auto& A) const {
	return !(*this == A);
}

bool Auto::operator>(const Auto& A) const {
	return classe > A.classe;
}

bool Auto::operator<(const Auto& A) const {
	return classe < A.classe;
}

void Auto::setModello(const char* _modello)
{
	if (modello)
		delete[] modello;

	int len = strlen(_modello) + 1;

	modello = new char[len];
	strcpy_s(modello, len, _modello);
}

void Auto::setClasse(const int _classe)
{
	if (_classe >= 2 && _classe <= 8)
		classe = _classe;
}

float Auto::calcolaPedaggio()
{
	float pedaggio = 0.0f;

	switch (classe) {
	case 2: 
		pedaggio = 1.0f;
		break;
	case 3: 
		pedaggio = 1.6f;
		break;
	case 4: 
		pedaggio = 2.05f;
		break;
	case 5: 
		pedaggio = 2.55f;
		break;
	case 6: 
		pedaggio = 3.0f;
		break;
	case 7: 
		pedaggio = 3.45f;
		break;
	case 8:
		pedaggio = 3.90f;
		break;
	}

	return pedaggio;
}

istream& Auto::input(istream& in)
{
	Veicolo::input(in);

	char _modello[100];
	int _classe;

	in >> _modello;
	setModello(_modello);
	in >> _classe;
	setClasse(_classe);

	return in;
}

ostream& Auto::output(ostream& out) const
{
	Veicolo::output(out);
	return out << '\t' << modello << " classe " << classe << std::endl;
}

istream& operator>>(istream& in, Auto& A) {
	return A.input(in);
}

ostream& operator<<(ostream& out, const Auto& A) {
	return A.output(out);
}

