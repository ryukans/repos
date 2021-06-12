#include "List.h"


List::~List()
{
	register Node* curr = head;
	Node* temp;
	while (curr) {
		temp = curr;
		curr = curr->next;
		delete temp;
	}

	delete curr;
}



void List::push(T t) 
{
	try {
		Node* n = new Node;
		setElem(t, n);
		n->next = head;
		head = n;
	}
	catch (const char* err) {
		cerr << err << endl;
	}
}

void List::pop(T& t)
{
	try { 
		getElem(t, head);
		Node* old = head;
		head = head->next;
		delete old;
	} 
	catch (const char* err) { 
		cerr << err << endl;
	}
}

void List::setElem(T& t, Node* n) throw (const char*) {
	if (has(t)) throw "Stack error: no dublicates allowed\n";
	n->elem = t;
}

void List::getElem(T& t, Node* n) throw (const char*) {
	if (empty()) throw "Stack error: No elements\n";
	t = n->elem;
}


bool List::has(const T& t) const
{
	Node* curr = head;
	bool found = false;
	while (curr && !found) {
		if (curr->elem == t)
			found = true;
		else
			curr = curr->next;
	}

	return found;
}


bool List::has(const T& t, int& pos) const
{
	Node* curr = head;
	bool found = false;
	while (curr && !found) {
		if (curr->elem == t) {
			pos = curr->elem;
			found = true;
		}
		else
			curr = curr->next;
	}

	return found;
}



void List::insert(const T t, Node* prev)
{
	Node* n = new Node;

	n->elem = t;
	n->next = prev->next->next;
	prev->next = n;
}

void List::insert(const T t, const int pos)
{
	if (pos == 1) {
		push(t);
		return;
	}

	Node* prev = head;
	for (int i = 1; i < pos - 1; i++)
		prev = prev->next;

	insert(t, prev);
}

void List::append(const T t)
{
	if (empty()) {
		push(t);
		return;
	}

	Node* tail = new Node;
	Node* curr = head;
	while (curr->next)
		curr = curr->next;

	tail->elem = t;
	tail->next = nullptr;
	curr->next = tail;
}	

void List::append_n(const T t)
{
	if (empty()) {
		push(t);
		return;
	}

	Node* prev = head;
	while (prev->next->next)
		prev = prev->next;

	insert(t, prev);
}

void List::remove(Node* prev)
{
	Node* old = prev->next;
	prev->next = prev->next->next; // rvalue will be null if removing tail

	delete old;
}

void List::remove(T& t, const int pos)
{
	if (pos == 1) {
		pop(t);
		return;
	}

	Node* prev = head;
	for (int i = 1; i < pos - 1; i++) //cycle must stops to the previous element you want to remove
		prev = prev->next;

	t = prev->next->elem;
	
	remove(prev);
}


void List::removeTail()
{
	Node* prev = head;
	while (prev->next->next)
		prev = prev->next;

	remove(prev);
}



ostream& operator<<(ostream& out, const List& L)
{
	List::Node* curr = L.head;
	while (curr) {
		out << curr->elem << ' ' << endl;
		curr = curr->next;
	}

	delete curr;
	return out;
}

istream& operator>>(istream& in, List& L)
{
	List::Node* n = new List::Node;
	List::T elem;

	in >> elem;
	in.ignore();
	L.push(elem);

	return in;
}


