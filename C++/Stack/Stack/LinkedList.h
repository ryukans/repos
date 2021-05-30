#pragma once
#include <iostream>

using namespace std;

namespace datastruct {

	const int listSize = 10;
	typedef int T;

	struct Node {
		T elem;
		Node* next;
	};
	

	class LinkedList
	{
		friend ostream& operator << (ostream&, const LinkedList&);

	public:
		LinkedList() : head(nullptr) {}
		~LinkedList() {
			Node* temp;
			while (head) {
				temp = head;
				head = head->next;
				delete temp;
			}
		}
		void push(const T);
		void pop(T&);
		void top(T&);
		void append(const T);
		void insert(const T, Node*) const;
		void remove(Node*);
		void removeTail(Node*);
		
		bool empty() const;
		bool full() const;
		bool has(const T) const;


	private:
		Node* head;
	};



}
