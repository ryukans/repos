#include "Queue.h"

bool Queue::append(const Media& file)
{
	if (used == size)
		return false;

	files[tail] = file;
	tail = (tail + 1) % size;
	++used;

	return true;
}

bool Queue::pop(Media& file)
{
	if (head == tail)
		return false;

	file = files[head];
	head = (head + 1) % size;
	--used;
}

bool Queue::top(Media& file)
{
	if (head == tail)
		return false;

	file = files[head];

	return true;
}

ostream& operator<<(ostream& out, const Queue& _this)
{
	for (int i = _this.head; i != _this.tail; i++)
		out << *_this.files[i] << std::endl;

	return out;
}
