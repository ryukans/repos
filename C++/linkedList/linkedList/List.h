#pragma once
#include <iostream>

using namespace std;

class List 
{ 
	typedef int T;

	struct	Node 
	{
		T	  elem;
		Node* next;
	};

	friend ostream& operator << (ostream&, const List&);
	friend istream& operator >> (istream&, List&);

	public:
					List() : head(nullptr){}
					~List();
			void	push(T);
			void	pop(T&);
			void	append(const T);
			void	append_n(const T);
			void	insert(const T, const int);
			void	remove(T&, const int);
			void	removeTail();
			bool	has(const T&) const;
			bool	has(const T&, int&) const;
	inline	bool	empty() const {	return head == nullptr;	}

	private:
			void	setElem(T&, Node*) throw (const char*);
			void	getElem(T&, Node*) throw (const char*);
			void	insert(const T, Node*);
			void	remove(Node*);

			Node*	head;
};


