#pragma once
#include <iostream>

using std::ostream;

class Data
{
	friend ostream& operator<<(ostream&, const Data&);

private:
	int giorno;
	int mese;
	int anno;

public:
	Data(const int = 1, const int = 1, const int = 1);
	Data(const Data&);

	void setData(const Data&);
	void setGiorno(const int);
	void setMese(const int);
	void setAnno(const int);

	const Data& operator=(const Data&);
	bool operator==(const Data&);
	bool operator!=(const Data&);

	Data getData() const { return *this; }
	int getGiorno() const { return giorno;}
	int getMese() const { return mese;}
	int getAnno() const { return anno;}
};

