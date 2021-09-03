#pragma once
#include <iostream>

using namespace std;

class Person
{
public:
	Person(string name, string lastname) : name(name), lastname(lastname) {}

	virtual void print() const
	{
		cout << "Person info\n" + name + ' ' + lastname << endl;
	}

private:
	string name;
	string lastname;


};

