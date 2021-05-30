#include "LinkedList.h"


namespace datastruct {

	void LinkedList::push(const T t)
	{
		Node* n = new Node;
		n->elem = t;
		n->next = head;	/* n becames the */ 
		head = n;		/*	new head  */
	}


	void LinkedList::pop(T& t)
	{
		Node* temp = head;	// store old head value memory allocation, in order to delete it later

		t = head->elem;
		head = head->next;
		delete temp;	// delete old head value memory allocation
	}

	void LinkedList::top(T& t) 
	{
		if (!empty())
			t = head->elem;
	}

	void LinkedList::append(const T t)
	{
		if (empty()) {
			push(t);
			return;
		}

		Node* tmp = head;
		while (tmp->next)
			tmp = tmp->next;

		Node* n = new Node;
		n->elem = t;
		n->next = nullptr;
		tmp->next = n;
	}

	void LinkedList::insert(const T t, Node* prev) const
	{
		Node* n = new Node;
	
		n->elem = t;
		n->next = prev->next;
		prev->next = n;
	}

	void LinkedList::remove(Node* prev)
	{
		Node* temp = prev->next;

		prev->next = prev->next->next;
		delete temp;
	}

	void LinkedList::removeTail(Node* prev)
	{
		Node* prev = head;

		while (prev->next->next)
			prev = prev->next;

		Node* temp = prev->next;
		prev->next = nullptr;
		delete temp;
	}

	bool LinkedList::empty() const
	{
		return head == nullptr;
	}

	bool LinkedList::full() const
	{
		return false;
	}

	bool LinkedList::has(const T t) const
	{
		Node* i = head;
		bool found = false;
		while (i && !found) {
			if (i->elem == t)
				found = true;
			else
				i = i->next;
		}

		return found;
	}


	
	ostream& operator<<(ostream& out, const LinkedList& L)
	{
		Node* temp = L.head;
		while (temp)
		{
			out << temp << endl;
			temp = temp->next;
		}
		return out;
	}

}
