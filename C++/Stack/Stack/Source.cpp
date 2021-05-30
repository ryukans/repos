#include "Stack.h"

namespace datastruct {

	Stack::Stack()
	{
		nelem = 0;
		S = new T[stackSize];
	}

	void Stack::push(const T t)
	{
		if (!full())
			S[nelem++] = t;
	}

	void Stack::pop(T& t)
	{
		if (!empty()) 
			t = S[--nelem];
	}

	void Stack::top(T& t)
	{
		if (!empty())
			t = S[nelem - 1];
	}


}