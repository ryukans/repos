#include "Queue.h"

Queue::Queue(const int s) : size(s), used(0), head(0), tail(0) {
	queue = new T[size];
}

Queue::Queue(const Queue& queue) {
	setQueue(queue);
}

Queue::~Queue() {
	delete[] queue;
}

const Queue& Queue::operator=(const Queue& other)
{
	if (this != &other)
		setQueue(other);

	return *this;
}

void Queue::setQueue(const Queue& other)
{
	if (queue)
		delete[] queue;

	size = other.size;
	used = other.used;
	head = other.head;
	tail = other.tail;
	queue = new T[size];

	for (int i = 0; i < size; i++)
		queue[i] = other.queue[i];
}

void Queue::append(const T& t)
{
	if (used == size) return;

	queue[tail] = t;
	tail = (tail + 1) % size;
	++used;
}

void Queue::pop(T& t)
{
	if (!used) return;

	t = queue[head];
	head = (head + 1) % size;
	--used;
}

void Queue::top(T& t)
{
	if (!used) return;

	t = queue[head-1];
}

/* DEBUG TEST */
void Queue::print_memory()
{
	std::cout << " | ";
	/*int i = 0;
	for (i = 0; i < used; i++) {
		std::cout << queue[i] << " | ";
	}

	for (; i < size; i++) {
		std::cout << "* | ";
	}*/

	for (int i = 0; i < size; i++)
	{
		std::cout << queue[i] << " | ";
	}

	std::cout << std::endl;
}

ostream& operator<<(ostream& out, const Queue& _this)
{
	!_this.used ? out << "No used\n" : out << " | ";

	for (int i = _this.head; i != _this.tail; i++)
		out << _this.queue[i] << " | ";
	out << std::endl;

	return out;
}
