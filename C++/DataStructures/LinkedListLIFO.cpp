#include "LinkedListLIFO.h"

LinkedListLIFO::~LinkedListLIFO()
{
	Node* tmp;
	while (head) {
		tmp = head;
		head = head->next;
		delete tmp;
	}
	head = nullptr;
}

void LinkedListLIFO::push(const T& t)
{
	Node* n = new Node;

	n->elem = t;
	n->next = head;
	head = n;
}

void LinkedListLIFO::insert(const T& t)
{
	if (!head || head->elem > t) {
		push(t);
		return;
	}

	Node* n = new Node;
	Node* prev, * curr;

	prev = head;
	while (prev->next && prev->next->elem < t)
		prev = prev->next;

	curr = prev->next;
	n->elem = t;
	n->next = curr;
}

void LinkedListLIFO::remove(const T& t)
{
	Node* prev;

	if (has(t, prev)) {
		Node* curr = prev->next;
		prev->next = curr->next;
		delete prev;
		delete curr;
	}
}

/*
void LinkedListLIFO::insert_r(const T& t)
{
	if (!head || head->elem > t) {
		push(t);
		return;
	}
	Node* prev = head;
	if (prev->next->elem < t) {
		prev = prev->next;
		insert_r(t);
	}
}
*/

void LinkedListLIFO::pop(T& t)
{
	if (!head)
		return;

	Node* tmp = head;

	t = head->elem;
	head = head->next;
	delete tmp;
}

void LinkedListLIFO::top(T& t)
{
	if (!head)
		return;

	t = head->elem;
}

bool LinkedListLIFO::has(const T& t)
{
	if (!head)
		return;

	Node* curr = head;
	while (curr && curr->elem != t)
		curr = curr->next;
	
	return (curr->elem == t);
}

bool LinkedListLIFO::has(const T& t, Node*& pos)
{
	if (!head)
		return;

	Node* curr = head;
	while (curr && curr->elem != t) {
		pos = curr;
		curr = curr->next;
	}

	return (curr->elem == t);
}