#pragma once
#include <iostream>
#include <cstring>
#include "Book.h"

class Book;
typedef Book* B;

using std::ostream;

class Author
{
	friend ostream& operator<<(ostream&, const Author&);

private:
	char* name;
	char* lastname;
	int bday;
	int capacity;
	int used;
	B* books;

public:
	Author();
	Author(const char*, const char*, const int);
	Author(const Author&);
	~Author();

	const Author& operator=(const Author&);

	const Author& getAuthor()	const	{ return *this; }
	int getCapacity()			const	{ return capacity; }
	int getSize()				const	{ return used; }
	void getBooks()				const;
	ostream& getBooks(ostream&) const;
	

	void setBooks(const B*, const int, const int);
	void setBooks(B*, int);
	void insertBook(const B&);
	void removeBook(B&);


};


