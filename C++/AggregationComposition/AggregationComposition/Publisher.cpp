#include "Publisher.h"


Publisher::Publisher() : name(new char[1]), address(new char[1]), phoneNumber(0), used(0), capacity(0), books()
{
	strcpy_s(name, 1, "");
	strcpy_s(address, 1, "");
}

Publisher::Publisher(const char* _name, const char* _address, const int _phoneNumber)
	:	name(new char[strlen(_name) + 1]), 
		address(new char[strlen(_address) + 1]), 
		phoneNumber(_phoneNumber),
		used(0), 
		capacity(0), 
		books()
{
	strcpy_s(name, strlen(_name) + 1, _name);
	strcpy_s(address, strlen(_address) + 1, _address);
}

Publisher::Publisher(const Publisher& p)
	:	name(new char[strlen(p.name) + 1]), 
		address(new char[strlen(p.address) + 1]), 
		phoneNumber(p.phoneNumber),
		used(p.used),
		capacity(p.capacity), 
		books(new L[capacity])
{
	strcpy_s(name, strlen(p.name) + 1, p.name);
	strcpy_s(address, strlen(p.address) + 1, p.address);

	for (int i = 0; i < capacity; i++)
		books[i] = p.books[i];
}

Publisher::~Publisher()
{
	delete[] name;
	delete[] address;
	delete[] books;
}

const Publisher& Publisher::operator=(const Publisher& P)
{
	if (this != &P){
		delete[] name;
		delete[] address;
		delete[] books;

		int n_len = strlen(P.name) + 1;
		int a_len = strlen(P.address) + 1;
		name = new char[n_len];
		address = new char[a_len];
		strcpy_s(name, n_len, P.name);
		strcpy_s(address, a_len, P.address);

		capacity = P.capacity;
		used = P.used;
		books = new L[capacity];
		for (int i = 0; i < capacity; i++)
			books[i] = P.books[i];

		phoneNumber = P.phoneNumber;
	}

	return *this;
}

void Publisher::insertBook(const char* code, const char* title, const int date, const int dateBuy, const int isbn)
{
	if (used == capacity) return;

	books[used]->setCode(code);
	books[used]->setTitle(title);
	books[used]->setDate(date);
	books[used]->setDateBuy(dateBuy);
	books[used]->setIsbn(isbn);

	used++;
}

void Publisher::getBooks()
{
	for (int i = 0; i < used; i++)
		std::cout << *books[i] << std::endl;
}

void Publisher::setBooks(const L* _books, const int _capacity, const int _used)
{
	delete[] _books;
	capacity = _capacity;
	used = _used;
	books = new L[capacity];

	for (int i = 0; i < capacity; i++)
		books[i] = _books[i];
}

void Publisher::insertBook(const B& book)
{
	if (used == capacity) return;

	books[used++] = book;
}

void Publisher::removeBook(char* code, char* title, int& date, int& dateBuy, int& isbn)
{
	if (!used) return;

	--used;
	//Book curr = *books[--used];
	strcpy_s(code, strlen(books[used]->getCode()) + 1, books[used]->getCode());
	strcpy_s(code, strlen(books[used]->getTitle()) + 1, books[used]->getTitle());
	date	= books[used]->getDate();
	dateBuy = books[used]->getDateBuy();
	isbn	= books[used]->getIsbn();
}

void Publisher::removeBook(B& book)
{
	if (!used) return;

	book = books[--used];
}

ostream& operator<<(ostream& out, const Publisher& P) {
	return out << P.name << " " << P.address << " " << P.phoneNumber << std::endl;
}