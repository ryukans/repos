#pragma once
#include <iostream>
#include <cstring>
#include "Book.h"

class Book;
typedef Book* L;

using std::ostream;


class Publisher
{

	friend ostream& operator<<(ostream&, const Publisher&);

private:
	int capacity;
	int used;	// riempimento
	char* name;
	char* address;
	int phoneNumber;
	L* books;	// lista di puntatori

public:

	Publisher();
	Publisher(const char* _name, const char* address, const int phoneNumber);
	Publisher(const Publisher&);
	~Publisher();

	const Publisher& operator=(const Publisher&);
	
	const Publisher& getPublisher() const { return *this; }
	int getCapacity()				const { return capacity; }
	int getSize()					const { return used; }
	void getBooks();

	void setBooks(const L*, const int, const int);
	void insertBook(const char*, const char*, const int, const int, const int);
	void insertBook(const B&);
	void removeBook(char*, char*, int&, int&, int&);
	void removeBook(B&);


};


