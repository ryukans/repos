#include "Mobile.h"

istream& Mobile::input(istream& in)
{
	Bolletta::input(in);
	setScatto(in);
	
	return in;
}

ostream& Mobile::output(ostream& out) const
{
	Bolletta::output(out);
	return out << scatto << std::endl;
}

Mobile::Mobile(const int scatto) : scatto(0)
{
	setScatto(scatto);
}

void Mobile::aggiornaBolletta(const int durata)
{
	Bolletta::aggiornaBolletta(durata);
	float nuovoImporto = getImporto() + scatto;
	setImporto(nuovoImporto);
}

void Mobile::setScatto(const int scatto)
{
	if (scatto > 0)
		this->scatto = scatto;
}

istream& Mobile::setScatto(istream& in)
{
	int scatto = 0;
	in >> scatto;
	setScatto(scatto);
	
	return in;
}