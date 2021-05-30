#include "Author.h"


Author::Author() : name(new char[1]), lastname(new char[1]), bday(0), used(0), capacity(0), books()
{
	strcpy_s(name, 1, "");
	strcpy_s(lastname, 1, "");
}

Author::Author(const char* _name, const char* _lastname, const int bd) :
	name(new char[strlen(_name) + 1]), lastname(new char[strlen(_lastname) + 1]), bday(bd), used(0), capacity(0), books()
{
	strcpy_s(name, strlen(_name) + 1, _name);
	strcpy_s(lastname, strlen(_lastname) + 1, _lastname);
}

Author::Author(const Author& A) :
	name(new char[strlen(A.name) + 1]), lastname(new char[strlen(A.lastname) + 1]), bday(A.bday), used(A.used), capacity(A.capacity), books(new B[capacity])
{
	strcpy_s(name, strlen(A.name) + 1, A.name);
	strcpy_s(lastname, strlen(A.lastname) + 1, A.lastname);

	for (int i = 0; i < capacity; i++)
		books[i] = A.books[i];
}


Author::~Author()
{
	delete[] name;
	delete[] lastname;
	delete[] books;
}

const Author& Author::operator=(const Author& A)
{
	if (this != &A) {
		delete[] name;
		delete[] lastname;
		delete[] books;

		int n_len = strlen(A.name) + 1;
		int ln_len = strlen(A.lastname) + 1;
		name = new char[n_len];
		lastname = new char[ln_len];
		strcpy_s(name, n_len, A.name);
		strcpy_s(lastname, ln_len, A.lastname);

		capacity = A.capacity;
		used = A.used;
		books = new B[capacity];
		for (int i = 0; i < capacity; i++)
			books[i] = A.books[i];
		
		bday = A.bday;
	}

	return *this;
}



void Author::setBooks(const B* _books, const int _capacity, const int _used)
{
	delete[] books;
	capacity = _capacity;
	used = _used;
	books = new B[capacity];

	for (int i = 0; i < capacity; i++)
		books[i] = _books[i];
}

/*
void Author::setBooks(B* _books, int _capacity)
{
	delete[] books;
	capacity = _capacity;
	books = new B[capacity];
	used = 0;
	Book empty;
	while (used < capacity && books[used++] != empty);


	for (int i = 0; i < capacity; i++)
		books[i] = _books[i];
}
*/

void Author::getBooks() const
{
	for (int i = 0; i < used; i++)
		std::cout << *books[i] << std::endl;
}

ostream& Author::getBooks(ostream& out) const
{
	for (int i = 0; i < used; i++)
		out << *books[i] << std::endl;
	
	return out;
}


void Author::insertBook(const B& book)
{
	if (used == capacity) return;

	books[used++] = book;
}

void Author::removeBook(B& book)
{
	if (!used) return;

	book = books[--used];
}

ostream& operator<<(ostream& out, const Author& A) {
	return out << A.name << " " << A.lastname << std::endl;
}

