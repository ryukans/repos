#include "Auto.h"


istream& Auto::input(istream& in) 
{
	Veicolo::input(in);
	
	char buffer[100];
	in.getline(buffer, 100);
	setAlimentazione(buffer);

	return in;
}

ostream& Auto::output(ostream& out) const
{
	Veicolo::output(out);

	return out << " " << alimentazione;
}

Auto::Auto() : Veicolo(), alimentazione(new char[1]) {
	strcpy_s(alimentazione, 1, "");
}

Auto::Auto(const char* tipo, const char* marca, const char* alimentazione) : Veicolo (tipo, marca) {
	setAlimentazione(alimentazione);
}

Auto::Auto(const Auto& A) : Veicolo(A) {
	setAlimentazione(A.alimentazione);
}

const Auto& Auto::operator=(const Auto& A)
{
	if (this != &A) {
		Veicolo::operator=(A);
		setAlimentazione(A.alimentazione);
	}

	return *this;
}

bool Auto::operator==(const Auto& A) const{
	return Veicolo::operator==(A) && !strcmp(alimentazione, A.alimentazione);
}

bool Auto::operator!=(const Auto& A) const {
	return !(*this == A);
}

void Auto::setAlimentazione(const char* _alimentazione)
{
	const int len = strlen(_alimentazione) + 1;

	delete[] alimentazione;
	alimentazione = new char[len];
	strcpy_s(alimentazione, len, _alimentazione);
}
