#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Book.h"
#include "Author.h"
#include "Publisher.h"

using namespace std;


int main()
{
	Book book("XXXXX", "Libro generico x", 5, 291998, 292000, 123456789);
	const int dim = 3;

	Chapter c1("Begin", 1);
	Chapter c2("Middle", 2);
	Chapter c3("End", 3);
	Chapter chapters[dim]{};
	chapters[0] = c1;
	chapters[1] = c2;
	//chapters[2] = c3;
	book.setChapters(chapters, dim);
	
	Author author("Aldo", "Baglio", 291998);
	book.setAuthor(&author);
	
	Publisher publisher("Editore generico", "Via Claudio", 9999999);
	book.setPublisher(&publisher);

	cout << book.getAuthor() << book.getPublisher() << endl;
	cout << book.getTotalCap() << " " << book.getNumOfCap() << endl;

	Book book2("YYYYY", "Libro generico y", 6, 291998, 292000, 123456789);
	Book book3("ZZZZZ", "Libro generico Z", 8, 291998, 292000, 123456789);
	Book* books[3]{};
	books[0] = &book;
	books[1] = &book2;
	books[2] = &book3;

	author.setBooks(books, 3, 3);
	//author.getBooks();
	
	cout << author.getCapacity() << " " << author.getSize() << endl;

	publisher.setBooks(books, 3, 3);
	

	cout << "a2\n";
	Author a2(author);
	a2.setBooks(books, 10, 3);
	a2.insertBook(&book);
	a2.getBooks();
	/*

	Publisher p2(publisher);
	//p2.getBooks();

	Author a3 = a2;
	a3.getBooks();

	Book book4("AXAXAXAXAXA", "Libro generico AX", chapters, dim, 291998, 29200, 123456789);
	
	book4.getChapters();
	*/
	return 0;
}


/*
	char* n{};
	char line[] = "Chapter ";
	for (int i = 0; i < 5; i++) {
		sprintf(n, "%d", i+1);
		strcat(line, n);
		book.insertChapter(line, i);
	}*/
