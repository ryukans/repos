#include "Queue.h"

namespace datastruct {
	
	void Queue::append(const T t)
	{
		if (full()) return;

		Q[tail] = t;
		tail = (tail + 1) % qsize;	// evalueate the module in order to fit within the range [0, qsize-1]
		++nelem;
	}

	void Queue::pop(T& t)
	{
		if (empty()) return;

		t = Q[head];
		head = (head + 1) % qsize;
		--nelem;
	}
	
	void Queue::top(T& t)
	{
		if(!empty())
			t = Q[nelem];
	}
}