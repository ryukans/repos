#pragma once
#include "utils.h"

class Data
{
	friend ostream& operator<<(ostream&, const Data&);
	friend istream& operator>>(istream&, Data&);

private:
	int giorno;
	int mese;
	int anno;


public:
	Data(const int = 0, const int = 0, const int = 0);
	Data(const Data&);

	const Data& operator=(const Data&);
	bool operator==(const Data&);
	bool operator!=(const Data&);

	void setGiorno(const int);
	void setMese(const int);	
	void setAnno(const int);
	int getGiorno() const { return giorno; } 
	int getMese() const { return mese; }
	int getAnno() const { return anno; }
};
