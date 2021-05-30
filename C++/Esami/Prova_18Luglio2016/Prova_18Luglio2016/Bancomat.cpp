#include "Bancomat.h"



Bancomat::Bancomat()
	: Carta(), attivata(false), pin(new char[PIN_SIZE + 1]), scadenza()
{
	strcpy_s(pin, PIN_SIZE + 1, "00000000");
}

Bancomat::Bancomat(const char* tipo, const char* intestatario, const char* numero, const int g, const int m, const int a)
	: Carta(tipo, intestatario, numero), pin(new char[PIN_SIZE+1]), attivata(false), scadenza(g, m, a)
{
	strcpy_s(pin, PIN_SIZE + 1, "00000000");
}

Bancomat::Bancomat(const char* tipo, const char* intestatario, const char* numero, const Data& _scadenza)
	: Carta(tipo, intestatario, numero), pin(new char[PIN_SIZE+1]), attivata(false), scadenza(_scadenza)
{
	strcpy_s(pin, PIN_SIZE + 1, "00000000");
}

Bancomat::Bancomat(const Bancomat& B)
	: Carta(B), attivata(B.attivata), pin(new char[PIN_SIZE+1]), scadenza(B.scadenza)
{
	strcpy_s(pin, PIN_SIZE + 1, B.pin);
}


Bancomat::~Bancomat() {
	delete[] pin;
}

const Bancomat& Bancomat::operator=(const Bancomat& B)
{
	if (this != &B) {
		delete[] pin;
		pin = new char[strlen(B.pin)+1];
		strcpy_s(pin, strlen(B.pin) + 1, B.pin);
		attivata = B.attivata;
		scadenza = B.scadenza;
	}
	
	return *this;
}

void Bancomat::attiva()
{
	attivata = true;
	setPin();
}


void Bancomat::setPin()
{
	delete[] pin;
	pin = new char[PIN_SIZE+1];

	char buffer[100] = "";
	const char* numero = getNumero();

	for (int i = 0; i < DIGIT; i++)
		buffer[i] = numero[i];

	strcat_s(buffer, 100, OFFSET);
	strcpy_s(pin, PIN_SIZE + 1, buffer);
	//std::cout << pin;
}

ostream& Bancomat::output(ostream& out) const
{
	Carta::output(out);
	attivata ? out << "Carta attivata\n" : out << "Carta non attivata\n";
	out << "Data scadenza: " <<  scadenza;

	return out;
}

bool Bancomat::check(const char* pin) const
{
	if (!attivata)
		return false;

	return !strcmp(this->pin, pin);
}

ostream& operator<<(ostream& out, const Bancomat& _this) {
	return _this.output(out);
}
