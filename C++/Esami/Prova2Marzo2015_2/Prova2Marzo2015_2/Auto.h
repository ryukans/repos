#pragma once
#include "Veicolo.h"

class Auto : public Veicolo 
{
	friend istream& operator>>(istream& in, Auto& _this) { return _this.input(in); }
	friend ostream& operator<<(ostream& out, const Auto& _this) { return _this.output(out); }

private:
	char* alimentazione;
	virtual istream& input(istream&);
	virtual ostream& output(ostream&) const;
	//virtual const char* toText() const;

public:
	Auto();
	Auto(const char*, const char*, const char*);
	Auto(const Auto&);
	virtual ~Auto() { delete[] alimentazione; }

	const Auto& operator=(const Auto&);
	bool operator==(const Auto&) const;
	bool operator!=(const Auto&) const;


	void setAlimentazione(const char*);
};

