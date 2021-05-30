#include <iostream>

using namespace std;

class Conto
{
public:
	Conto()
	{
		nmov = 0;
		nmax = 10;
		movimenti = new float[nmax];
	}
	Conto(string titolare, int conto, int nmax = 10);
	~Conto() { delete[] movimenti; }
	virtual float calcolaSpese();


protected:
	string titolare;
	float* movimenti;
	int conto;
	int nmov;
	int nmax;
};

Conto::Conto()
{
}

Conto::~Conto()
{
}