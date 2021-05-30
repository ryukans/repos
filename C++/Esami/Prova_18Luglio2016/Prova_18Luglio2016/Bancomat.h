#pragma once
#include "Carta.h"
#include "Data.h"

static const int OFFSET_SIZE = 3;
static const int PIN_SIZE = DIGIT + OFFSET_SIZE;
static const char OFFSET[OFFSET_SIZE+1] = "XXX";

class Bancomat : public Carta
{
	friend ostream& operator<<(ostream&, const Bancomat&);

private:
	char* pin;
	bool attivata;
	Data scadenza;
	void setPin();

protected:
	virtual ostream& output(ostream&) const;

public:
	Bancomat();
	Bancomat(const char*, const char*, const char*, const int, const int, const int);
	Bancomat(const char*, const char*, const char*, const Data&);
	Bancomat(const Bancomat&);
	~Bancomat();

	const Bancomat& operator=(const Bancomat&);

	void setScadenza(const Data& scadenza) { this->scadenza = scadenza; }
	Data getScadenza() const { return scadenza; }

	void attiva();
	virtual bool check(const char*) const;
};

