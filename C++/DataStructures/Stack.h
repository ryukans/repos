#pragma once
#include <iostream>

typedef int T;

using std::ostream;
using std::istream;

class Stack
{
	friend ostream& operator<<(ostream&, const Stack&);
	friend istream& operator>>(istream&, Stack&);

private:
	T* stack;
	int head;
	int size;

public:
	Stack(const int = 0);
	Stack(const Stack&);
	~Stack();

	const Stack& operator=(const Stack&);
	
	void setStack(const Stack&);

	void push(const T&);
	void insert(const T&);
	void pop(T&);
	void top(T&);
	
};

