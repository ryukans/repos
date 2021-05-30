#include "List.h"

List::List(int n) : size(n), nelem(0) 
{
	try
	{
		/*Vine invocato il metodo setList:
			-controllo variabile size; l'utente potrebe inserire in valore negativo*/
		setList(size);
	}
	catch (const char* errmsg)
	{
		cerr << errmsg << endl;
	}
}


List::List(const E& e) : size(1), nelem(1)
{
	/*Non viene invocato il metodo setList:
		-ridondanza controllo variabile size; size = 1 sempre */

	list = new E[size];
	list[0] = e;	//utilizza operator= nella classe Entry
}


List::List(const List& L) : size(L.size), nelem(L.nelem)
{
	/*Non viene invocato il metodo setList:
		-ridondanza controllo variabile size; size > 0 per ogni lista L*/

	list = new E[size];
	for (int i = 0; i < size; i++)
		list[i] = L.list[i];
}

List::~List()
{
	delete[] list;
	nelem = 0;
}


void List::setList(int size) throw (const char*)
{
	if (size < 0)
		throw "Error: bad size value\n";

	delete[] list;
	list = new E[size];

	this->size = size;	//Controllare possibile ridondanza
}

istream& List::setList(istream& in)
{
	int i;
	for (i = 0; i < size; i++)
		in >> list[i];

	nelem = i;

	return in;
}

ostream& List::getList(ostream& out) const
{
	for (int i = 0; i < nelem; i++)
		out << list[i] << ' ' << endl;

	return out;
}

const List& List::operator=(const List& L)
{
	if (this != &L)
	{
		delete[] list;
		size	= L.size;
		nelem	= L.nelem;
		list	= new E[size];

		for (int i = 0; i < size; i++)
			list[i] = L.list[i];
	}

	return *this;
}

bool List::operator==(const List& L) const
{
	int i = 0;
	while ((i < nelem) && (list[i] == L.list[i]))
		++i;

	return (i == nelem) ? true : false;
}

bool List::operator!=(const List& L) const {
	return !(list == L.list);
}

E& List::operator[](int index) const throw (const char*)
{
	if (index < 0 || index > size) 
		throw "Error: out of bonds\n";
	
	return list[index];
}

void List::insert(const E& e) throw (const char*)
{
	if (isFull())
		throw "Error: list is full";

	list[nelem++] = e;
}


bool List::hasEntry(E& e, int& pos)
{
	int i = 0;

	while (i < nelem && list[i] != e)
		++i;

	if (i < nelem) {
		pos = i;
		return true;
	}
	return false;
}
