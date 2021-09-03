#pragma once
#include <iostream>

typedef int T;

class LinkedListLIFO
{
	struct Node
	{
		T elem;
		Node* next;
	};

private:
	Node* head;

public:
	LinkedListLIFO() : head(nullptr) {};
	~LinkedListLIFO();

	void push(const T&);
	void insert(const T&);
	void remove(const T&);
	//void insert_r(const T&);
	void pop(T&);
	void top(T&);
	bool has(const T&);
	bool has(const T&, Node*&);

};

