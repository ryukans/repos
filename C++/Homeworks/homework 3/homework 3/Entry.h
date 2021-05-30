#pragma once

#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

class Entry {

private:
	int key;
	char* info;

public:

	Entry(const int = 0, const char* = "");

	~Entry()
	{
		delete[] info;
		key = 0;
	}

	void setEntry(
		const int = 0,
		const char* = ""
	);

	void getEntry();
		
	void copy( 
		const Entry&
	);

	static void copy(
		Entry &,
		const Entry&
	);
	
	bool equal(
		const Entry&
	);
	
	static bool equal(
		const Entry&,
		const Entry&
	);

	/*
	bool greaterThan(
		const Entry&, 
		const Entry&
	);
	*/




































};