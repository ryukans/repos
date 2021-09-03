#pragma once
#include <iostream>

typedef int T;

using std::ostream;
using std::istream;

class Queue
{
	friend ostream& operator<<(ostream&, const Queue&);
	//friend istream& operator>>(istream&, Queue&);

private:
	T* queue;
	int head;
	int tail;
	int used; // logical storage
	int size; 

public:
	Queue(const int = 0);
	Queue(const Queue&);
	~Queue();

	const Queue& operator=(const Queue&);

	void setQueue(const Queue&);

	void append(const T&);
	void pop(T&);
	void top(T&);
	void print_memory(); /* DEBUG TEST */
};

