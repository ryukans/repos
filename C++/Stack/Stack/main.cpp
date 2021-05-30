#include "Stack.h"
#include "Queue.h"

using namespace std;
using datastruct::Stack;
using datastruct::Queue;

int main()
{
	
	Stack s;
	int d = -1;

	s.push(10);
	s.top(d);
	cout << d << endl;

	s.push(55);
	s.top(d);
	cout << d << endl;

	Queue q;
	int t = -1;

	q.append(22);



	return 0;
}