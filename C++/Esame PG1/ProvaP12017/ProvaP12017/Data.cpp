#include "Data.h"

Data::Data(const int giorno, const int mese, const int anno)
{
	setGiorno(giorno);
	setMese(mese);
	setAnno(anno);
}

Data::Data(const Data& D) {
	*this = D;
}

const Data& Data::operator=(const Data& D)
{
	giorno = D.giorno;
	mese = D.mese;
	anno = D.anno;

	return *this;
}

bool Data::operator==(const Data& D) {
	return (giorno == D.giorno) && (mese = D.mese) && (anno = D.anno);
}

bool Data::operator!=(const Data& D) {
	return !(*this != D);
}

void Data::setGiorno(const int giorno)
{
	if (!(giorno > 0 && giorno <= 31))
		return;

	this->giorno = giorno;
}

void Data::setMese(const int mese)
{
	if (!(mese > 0 && mese <= 12))
		return;
	this->mese = mese;
}

void Data::setAnno(const int anno)
{
	if (!(anno > 1970))
		return;
	this->anno = anno;
}

ostream& operator<<(ostream& out, const Data& D) {
	return out << D.giorno << '/' << D.mese << '/' << D.anno << endl;
}

istream& operator>>(istream& in, Data& D)
{
	int gg, mm, aa;
	in >> gg >> mm >> aa;
	D.setGiorno(gg);
	D.setMese(mm);
	D.setAnno(aa);

	return in;
}
