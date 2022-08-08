#include "Entry.h"


Entry::Entry(const int key, const char* info) 
{
	setEntry(key,info);
}
/*
Entry::Entry(Entry* e)
{
	setEntry(e->key, e->info);
}*/


void Entry::getEntry()
{
	cout << key << ' ';
	info == NULL ? cout << "Empty\n" : cout << info << endl;
}


void Entry::setEntry(const int key, const char* info)
{

	this->info = new char[strlen(info) + 1];
	this->info = (char*)info;
	this->key = key;
	;
}

void Entry::copy(const Entry& EO)
{
	if (this != &EO) { //constrolla che non si stia copiando un record su se stesso
		if (strlen(this->info) != strlen(EO.info)) {
			delete[] this->info;
			this->info = new char[strlen(EO.info) + 1];
		}
		this->info = (char*)EO.info;
		//strcpy_s(this->info, strlen(EO.info), EO.info);
		this->key = EO.key;
	}
	//se si sta copiando un record su se stesso non fa nulla
}

void Entry::copy(Entry& ED, const Entry& EO)
{
	if (&ED != &EO) { 
		if (strlen(ED.info) != strlen(EO.info)) {
			delete[] ED.info;
			ED.info = new char[strlen(EO.info) + 1];
		}
		ED.info = (char*)EO.info;
		//strcpy_s(ED.info, strlen(EO.info), EO.info);
		ED.key = EO.key;
	}

}

bool Entry::equal(const Entry &E)
{
	return (this->key == E.key) && (!strcmp(this->info, E.info));
}

bool Entry::equal(const Entry &E1, const Entry &E2)
{
	return ((E1.key == E2.key) && (!strcmp(E1.info, E2.info)));
}

/*
void Entry::read(Entry& E)
{
	char buffer[100];
	cin >> E.key;
	cin.getline(buffer, 100);
	delete[] E.info;
	E.info = new char[strlen(buffer) + 1];
	strcpy_s(E.info, strlen(buffer), buffer);
}*/




/*
bool Entry::greaterThan(const Entry& E1, const Entry& E2)
{
	return (E1.key > E2.key);
}
*/