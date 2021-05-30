
#include "Conto.h"
class Ordinario : public Conto
{	
public:
	Ordinario() : Conto(), tasso(0.2), nop(3) { movimenti = new float[nmax]; }
	Ordinario(string titolare, int conto, int nmax, float tasso, int nop);
	Ordinario(const Ordinario&);
	virtual float calcolaSpese();

protected:
	float tasso;
	int nop;

};
