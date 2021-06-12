#pragma once
#include "Key.h"
#include <vector>


class Piano
{
	friend ostream& operator<<(ostream&, const Piano&);

private:
	static const int KEYS = 7;
	//std::vector<Key> p;
	Key piano[KEYS];

public:
	Piano();
	void play();


};

