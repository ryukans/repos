#include "Data.h"

Data::Data(const int giorno, const int mese, const int anno)
{
	setGiorno(giorno);
	setMese(mese);
	setAnno(anno);
}

Data::Data(const Data& data) {
	setData(data);
}

void Data::setData(const Data& data)
{
	setGiorno(data.giorno);
	setMese(data.mese);
	setAnno(data.anno);
}

void Data::setGiorno(const int g)
{
	if (g >= 1 && g <= 31)
		giorno = g;
}

void Data::setMese(const int m)
{
	if (m >= 1 && m <= 12)
		mese = m;
}

void Data::setAnno(const int a)
{
	if (a >= 1970)
		anno = a;
}

const Data& Data::operator=(const Data& data)
{
	setData(data);

	return *this;
}

bool Data::operator==(const Data& data) {
	return (giorno == data.giorno) && (mese == data.mese) && (anno == data.anno);
}

bool Data::operator!=(const Data& data) {
	return !(*this == data);
}

ostream& operator<<(ostream& out, const Data& _this) {
	return out << _this.giorno << '/' << _this.mese << '/' << _this.anno << std::endl;
}
