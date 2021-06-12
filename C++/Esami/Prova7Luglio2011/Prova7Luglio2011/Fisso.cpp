#include "Fisso.h"


istream& Fisso::input(istream& in)
{
	Bolletta::input(in);
	char buffer[100];
	in >> buffer;
	strcpy_s(indirizzo, strlen(buffer) + 1, buffer);
	in >> canone;
}

ostream& Fisso::output(ostream& out) const
{
	Bolletta::output(out);
	return out << indirizzo << " " << canone << std::endl;
}

Fisso::Fisso() : Bolletta(), indirizzo(new char[1]), canone(0.0f) {
	strcpy_s(indirizzo, 1, "");
}

Fisso::Fisso(const char* cc, const float imp, const float cSec, const int nTel, const char* _indirizzo, const float _canone)
	: Bolletta(cc, imp, cSec, nTel)
{
	setFisso(_indirizzo, _canone);
}

Fisso::Fisso(const Bolletta& B, const char* _indirizzo, const float _canone)
	: Bolletta(B)
{
	setFisso(_indirizzo, _canone);
}

Fisso::Fisso(const Fisso& F)
	: Bolletta(F)
{
	setFisso(F);
}

Fisso::~Fisso() {
	delete[] indirizzo;
}

const Fisso& Fisso::operator=(const Fisso& F)
{
	if (this != &F) {
		Bolletta::operator=(F);
		setFisso(F);
	}

	return *this;
}

void Fisso::setFisso(const char* _indirizzo, const float _canone)
{
	int len = strlen(_indirizzo) + 1;

	delete[] indirizzo;
	indirizzo = new char[len];
	strcpy_s(indirizzo, len, _indirizzo);
	canone = _canone;
}

void Fisso::setFisso(const Fisso& F) {
	setFisso(F.indirizzo, F.canone);
}

void Fisso::aggiornaBolletta(const int durata) {
	Bolletta::aggiornaBolletta(durata);
}

istream& operator>>(istream& in, Fisso& F) {
	return F.input(in);
}

ostream& operator<<(ostream& out, const Fisso& F) {
	return F.output(out);
}
