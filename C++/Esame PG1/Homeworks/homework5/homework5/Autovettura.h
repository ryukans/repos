#pragma once
#include "Veicolo.h"

class Auto : public Veicolo
{
	friend istream& operator>>(istream&, Auto&);
	friend ostream& operator<<(ostream&, const Auto&);

private:
	char* modello;
	int classe;

protected:
	virtual istream& input(istream&);
	virtual ostream& output(ostream&) const;

public:
	Auto();
	Auto(const char*, const char*, const char*, const int);
	//Auto(const char*, const int, const Veicolo&);
	Auto(const Auto&);
	~Auto();

	const Auto& operator = (const Auto&);
	bool operator == (const Auto&) const;
	bool operator != (const Auto&) const;
	bool operator >  (const Auto&) const;
	bool operator <  (const Auto&) const;
	
	void setModello(const char*);
	void setClasse(const int);
	const char* getModello() const {return modello;}
	int getClasse() const {return classe;}

	virtual float calcolaPedaggio();


};
