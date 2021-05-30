#include "Stack.h"
#include "Queue.h"
#include "LinkedListLIFO.h"

using namespace std;

int main()
{
	/*
	Stack s(5);

	s.push(4);
	s.push(6);
	s.push(2);

	cout << s;
	
	s.insert(1);
	cout << s;
	*/

	/*
	Queue q(5);

	q.append(2);
	q.append(3);
	q.append(4);
	
	
	cout << q;
	q.print_memory();

	cout << endl;
	int x, y, z;
	q.pop(x);
	
	cout << q;
	q.print_memory();
	cout << x;

	q.pop(y);
	q.pop(z);
	cout << endl << y << " " << z << endl;

	cout << q;
	q.print_memory();
	*/

	LinkedListLIFO list;

	list.push(5);

	return 0;
}

