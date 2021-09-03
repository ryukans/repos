#include "Stack.h"

Stack::Stack(const int s) : head(0), size(s) {
	stack = new T[size];
}

Stack::Stack(const Stack& other) {
	setStack(other);
}

Stack::~Stack() {
	delete[] stack;
}

const Stack& Stack::operator=(const Stack& other)
{
	if (this != &other) {
		setStack(other);
	}
	return *this;
}

void Stack::setStack(const Stack& other)
{
	if (stack)
		delete[] stack;

	head = other.head;
	size = other.size;
	stack = new T[size];
	for (int i = 0; i < head; i++)
		stack[i] = other.stack[i];
}

void Stack::push(const T& t)
{
	if (head == size)
		return;

	stack[head++] = t;
}

void Stack::insert(const T& t)
{
	if (head == size) return;
	if (head == 0 || stack[head-1] > t) {
		push(t);
		return;
	}

	int i = 0;
	while (i < head && stack[i] < t)
		++i;

	//if (i == head) return;

	stack[i] = t;
}

void Stack::pop(T& t)
{
	if (head == 0)
		return;

	t = stack[--head];
}

void Stack::top(T& t)
{
	if (head == 0) return;

	t = stack[head-1];
}

ostream& operator<<(ostream& out, const Stack& _this)
{
	out << " | ";
	for (int i = 0; i < _this.head; i++)
		out << _this.stack[i] << " | ";
	out << std::endl;
	
	return out;
}

istream& operator>>(istream& in, Stack& _this)
{
	T t;
	for (int i = 0; i < _this.size; i++) {
		in >> t;
		_this.push(t);
	}

	return in;
}
