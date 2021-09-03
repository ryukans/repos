#pragma once
#include "Person.h"


class Employee : public Person
{

public:
	Employee(string name = "", string lastname = "", string firm = "", int lvl = 0) : Person(name, lastname), firm(firm), lvl(lvl) {}

	virtual void print() const
	{
		cout << "Employee info\n" + firm + ' ' << lvl << endl;
	}

private:
	string firm;
	int lvl;











};

