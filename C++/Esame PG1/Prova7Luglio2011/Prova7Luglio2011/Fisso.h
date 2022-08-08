#pragma once
#include "Bolletta.h"

class Fisso : public Bolletta
{
	friend istream& operator>>(istream&, Fisso&);
	friend ostream& operator<<(ostream&, const Fisso&);

private:
	char* indirizzo;
	float canone;

protected:
	virtual istream& input(istream&);
	virtual ostream& output(ostream&) const;

public:
	Fisso();
	Fisso(const char*, const float, const float, const int, const char*, const float);
	Fisso(const Bolletta&, const char*, const float);
	Fisso(const Fisso&);
	virtual ~Fisso();

	const Fisso& operator=(const Fisso&);

	void setFisso(const char*, const float);
	void setFisso(const Fisso&);

	virtual void aggiornaBolletta(const int);
};
