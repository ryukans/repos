#pragma once
#include "MultimediaFile.h"

typedef MultimediaFile* Media;


class Queue
{
	friend ostream& operator<<(ostream&, const Queue&);

private:
	static const int size = 100;
	Media files[size];
	int head;
	int tail;
	int used;

public:
	Queue() : head(0), tail(0), used(0), files() {};
	
	bool append(const Media&);
	bool pop(Media&);
	bool top(Media&);


};

