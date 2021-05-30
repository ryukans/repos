#pragma once
#include <iostream>
#include <cstring>
#include "Chapter.h"
#include "Author.h"
#include "Publisher.h"

class Author;
class Publisher;
typedef Chapter C;

using std::ostream;

class Book
{
	friend ostream& operator<<(ostream&, const Book&);

private:
	char* code;
	char* title;
	int	date;
	int dateBuy;
	int isbn;
	int totalCap; // capacity
	int numOfCap; // usage
	C* chapters;
	Author* author;
	Publisher* publisher;

public:
	Book();
	Book(const char* code, const char* title, const int totalCap, const int date, const int dateBuy, const int isbn);
	Book(const char* code, const char* title, const C* chapters, const int totalCap, const int date, const int dateBuy, const int isbn);
	Book(const Book&);
	~Book();

	const Book& operator=(const Book&);

	void setCode(const char*);
	void setTitle(const char*);
	void setDate(const int _date)		{ date = _date;}
	void setDateBuy(const int _dateBuy)	{ dateBuy = _dateBuy;}
	void setIsbn(const int _isbn)		{ isbn = _isbn;}
	void setAuthor(Author*& A)			{ author = A; }
	void setPublisher(Publisher*& P)	{ publisher = P; }
	void setChapters(const C*, const int, const int);
	void setChapters(const C*, const int);
	void insertChapter(const char*, const int); //push
	C	 removeChapter();						//pop

	const char* getCode()	const	{ return code;}
	const char* getTitle()	const	{ return title;}
	int getDate()			const	{ return date;}
	int getDateBuy()		const	{ return dateBuy;}
	int getIsbn()			const	{ return isbn;}
	int getTotalCap()		const	{ return totalCap;}
	int getNumOfCap()		const	{ return numOfCap;}
	void getChapters()		const;
	/*
		Siccome sussiste una relazione incrociata tra le classi allora l'implementazione dei seguenti metodi 
		viene scritte nel file source
	*/
	Author getAuthor() const;	
	Publisher getPublisher() const;


};

