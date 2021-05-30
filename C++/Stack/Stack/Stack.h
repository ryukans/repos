#pragma once
#include <iostream>

namespace datastruct {

	const int stackSize = 10;
	typedef int T;

	class Stack
	{

	public:


		Stack();
		~Stack() { delete[] S; }



		void push(const T);			//insert element on top
		void pop(T&);				//remove element on top; returs element from stack
		void top(T&);				//peek
		bool search(const T);		//applies binary search in order to find given element
		bool empty() const { return nelem == 0; }
		bool full()	const { return nelem == stackSize; }



	private:
		int nelem;
		T* S;

	};
}