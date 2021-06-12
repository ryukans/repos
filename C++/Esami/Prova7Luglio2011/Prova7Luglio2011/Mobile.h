#pragma once
#include "Bolletta.h"

class Mobile : public Bolletta
{
private:
	int scatto;

protected:
	virtual istream& input(istream&);
	virtual ostream& output(ostream&) const;

public:
	Mobile(const int = 0);

	void setScatto(const int);
	istream& setScatto(istream&);

	virtual void aggiornaBolletta(const int);
};
