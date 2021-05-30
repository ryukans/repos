#pragma once
#include <iostream>

namespace datastruct {

	const int qsize = 10;
	typedef int T;

	class Queue
	{
	public:
		Queue() : nelem(0), head(0), tail(0), Q(new T[qsize]) {}
		~Queue() { delete[] Q; }
		
		void append(const T);
		void pop(T&);
		void top(T&);
		bool empty() const { return nelem == 0; }
		bool full() const { return nelem == qsize; }
		
	private:
		int nelem;
		int head;
		int tail;
		T* Q;







	};


}