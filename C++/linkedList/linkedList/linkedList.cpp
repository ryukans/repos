#include "List.h"

int main()
{
	List a;

	for (int i = 0; i < 3; i++)
		cin >> a;
	
	cout << a << endl;

	//Test append 
	
	/*a.append(1);
	cout << a << endl;
	*/

	a.insert(1, 2);
	cout << a << endl;

	int x = -1;
	a.remove(x, 2);
	cout << a << endl << x << endl;

	// Test remove tail 
	/*a.removeTail();
	cout << "Tail's gone\n" << a << endl;
	*/


	return 0;
}

