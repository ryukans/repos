#include "Bolletta.h"
#include <cstring>

istream& Bolletta::input(istream& in)
{
	char buffer[100];
	in >> buffer;
	setCodiceCliente(buffer);

	in >> costoAlSecondo;
	in >> numTelefonate;
	in >> importo;

	return in;
}

ostream& Bolletta::output(ostream& out) const {
	return out << codiceCliente << " " << numTelefonate << " " << importo << std::endl;
}

Bolletta::Bolletta() : codiceCliente(new char[1]), importo(0.0f), costoAlSecondo(0.0f), numTelefonate(0)
{
	strcpy_s(codiceCliente, 1, "");
}

Bolletta::Bolletta(const char* cc, const float imp, const float cSec, const int nTel)  {
	setBolletta(cc, imp, cSec, nTel);
}

Bolletta::Bolletta(const Bolletta& B) {
	setBolletta(B);
}

Bolletta::~Bolletta() {
	delete[] codiceCliente;
}

const Bolletta& Bolletta::operator=(const Bolletta& B)
{
	if (this != &B)
		setBolletta(B);
	
	return *this;
}

void Bolletta::setBolletta(const char* cc, const float imp, const float cSec, const int nTel)
{
	setCodiceCliente(cc);
	importo = imp;
	costoAlSecondo = cSec;
	numTelefonate = nTel;
}

void Bolletta::setBolletta(const Bolletta& B) {
	setBolletta(B.codiceCliente, B.importo, B.costoAlSecondo, B.numTelefonate);
}

void Bolletta::setCodiceCliente(const char* cc)
{
	int len = strlen(cc) + 1;

	delete[] codiceCliente;
	codiceCliente = new char[len];
	strcpy_s(codiceCliente, len, cc);
}

void Bolletta::setImporto(const float importo)
{
	if (importo > 0)
		this->importo = importo;
}

void Bolletta::aggiornaBolletta(const int durata)
{
	importo += costoAlSecondo*durata;
	++numTelefonate;
}

istream& operator>>(istream& in, Bolletta& B) {
	return B.input(in);
}

ostream& operator<<(ostream& out, const Bolletta& B) {
	return B.output(out);
}
