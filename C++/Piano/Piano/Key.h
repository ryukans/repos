#pragma once
#include <iostream>
#include <string>

using std::string;
using std::ostream;

class Key
{
	friend ostream& operator<<(ostream&, const Key&);

private:
	string note;
	float frequency;

	void set_note(const string&);
	void set_frequency(const float);
	
public:
	Key(const string& note = "MISSING NOTE", const float frequency = 0.0f);
	void set_key(const string&, const float);

	
};

