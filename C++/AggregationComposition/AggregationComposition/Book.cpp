#include "Book.h"

Book::Book() 
	: totalCap(0), numOfCap(0), chapters(new C[totalCap]), code(new char[1]), title(new char[1]), date(0), dateBuy(0), isbn(0), author(nullptr), publisher(nullptr)
{
	strcpy_s(code, 1, "");
	strcpy_s(title, 1, "");
}

Book::Book(const char* code, const char* title, const int _totalCap, const int _date, const int _dateBuy, const int _isbn)
{
	totalCap = _totalCap;
	numOfCap = 0;
	chapters = new C[totalCap];

	setCode(code);
	setTitle(title);

	date = _date;
	dateBuy = _dateBuy;
	isbn = _isbn;
	author = nullptr;
	publisher = nullptr;

}

Book::Book(const char* code, const char* title, const C* chapters, const int _totalCap, const int _date, const int _dateBuy, const int _isbn)
{
	setCode(code);
	setTitle(title);
	setChapters(chapters, totalCap);

	date = _date;
	dateBuy = _dateBuy;
	isbn = _isbn;
	author = nullptr;
	publisher = nullptr;

}

Book::Book(const Book& b)
{
	setCode(b.code);
	setTitle(b.title);
	setChapters(b.chapters, b.totalCap, b.numOfCap);

	date = b.date;
	dateBuy = b.dateBuy;
	isbn = b.isbn;
	author = b.author;
	publisher = b.publisher;

	//*this = b; sfrutterei l'overload di operator= della classe Book, avrebbe senso ??? 		
}


Book::~Book()
{
	delete[] code;
	delete[] title;
	delete[] chapters;
}

const Book& Book::operator=(const Book& book)
{
	if (this != &book) {
		setCode(book.code);
		setTitle(book.title);
		setChapters(book.chapters, book.totalCap, book.numOfCap);

		date = book.date;
		dateBuy = book.dateBuy;
		isbn = book.isbn;
		author = book.author;
		publisher = book.publisher;
	}

	return *this;
}

void Book::setCode(const char* _code)
{
	const int len = strlen(_code);

	delete[] code;
	code = new char[len + 1];
	len != 0 ? strcpy_s(code, len + 1, _code) : strcpy_s(code, 1, "");
}

void Book::setTitle(const char* _title)
{
	const int len = strlen(_title);

	delete[] title;
	title = new char[len + 1];
	len != 0 ? strcpy_s(title, len + 1, _title) : strcpy_s(title, 1, "");
}


void Book::setChapters(const C* _chapters, const int _totalCap, const int _numOfCap)
{
	// TODO: controllo variabili di ingresso per la capacità e riempimento e lanciare un eccezione nel caso siano minori di zero
	totalCap = _totalCap;
	numOfCap = _numOfCap;
	delete[] chapters;
	chapters = new C[totalCap];

	for (int i = 0; i < totalCap; i++)
		chapters[i] = _chapters[i];
}

/*
	Funzione set alternativa che non utilizza la variabile numOfCap per il riempimento del vettore,
	utilizza un ciclo while per capire in il riempimento del vettore
	TODO: controllo variabile di ingresso per la capacità e lanciare un eccezione nel caso sia minore di zero
*/
void Book::setChapters(const C* _chapters, const int _totalCap)
{
	totalCap = _totalCap;
	delete[] chapters;
	chapters = new C[totalCap];
	
	numOfCap = 0;
	Chapter empty;	// c'è un modo migliore di procedere ? 
	while (numOfCap < totalCap && _chapters[numOfCap] != empty)
		++numOfCap;
	
	for (int i = 0; i < totalCap; i++)
		chapters[i] = _chapters[i];
}

/*
	Semplice funzione di stampa, non ritorna alcun valore
*/
void Book::getChapters() const
{
	for (int i = 0; i < numOfCap; i++)
		std::cout << chapters[i] << std::endl;
}

void Book::insertChapter(const char* title, const int capNumber) {
	chapters[numOfCap++].setChapter(title, capNumber);
}

C Book::removeChapter() {
	return chapters[--numOfCap];
}

Author Book::getAuthor() const {
	return author->getAuthor();
	//return (*author); alternativamente 
}

Publisher Book::getPublisher() const {
	return publisher->getPublisher();
}

ostream& operator<<(ostream& out, const Book& B) {
	return out << B.title << " " << B.date << " " << B.isbn << std::endl;
}
