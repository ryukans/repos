#include "Entry.h"
#include "List.h"

using namespace std;

int main()
{
//Entry e;
	Entry e2(10, "ABC");
	Entry e3(e2);	// Test costruttore di copia e overload operatore di assegnazione (vedi definizione costruttore di copia)
	Entry e4(11, "DEF");
	Entry e5(12, "GHI");

	//cout << e << endl;
	cout << e2 << endl;
	cout << e3 << endl;

	/*Test overload operatori isteam >> e ostream << */
	//cin >> e;
	//cout << e;

	/*Test overload operatore di assegnazione*/
	//e = e2;
	//cout << e2;

	

	cout << endl <<  "List Test\n" << endl;

	List a;
	List b(4);
	List c(e4);
	List d;

	/*Test overload operatore ostream >> e funzione insert() */
	cout << a << endl;
	a.insert(e3);
	cout << a;

	/*Test costruttore di copia*/
	//List d(c);
	//cout << d;

	/*Test overload opeatore istream << e ostream >> */
	cin >> d;
	cout << d;
	
	/*Test funzione hasEntry()*/
	//int pos = -1;
	//c.hasEntry(e4, pos) ? cout << "Yes, at index: " << pos << endl : cout << "No" << endl;

	/*Test funzione insert */
	//b.insert(e3);
	//b.insert(e4);
	//b.insert(e5);
	
	//cout << b << endl;

	/*Test overload operatore di assegnazione */
	a = b;
	cout << a;

	b.insert(e5);
    b.isFull() ? cout << "Full" << endl : cout << "Not full" << endl;


	
	return 0;
}
















