#pragma once
#include <iostream>
#include <cstring>

using std::ostream;

class Chapter
{
	friend ostream& operator<<(ostream&, const Chapter&);

private:
	char* title;
	int number;

public:
	Chapter();
	Chapter(const char*, const int);
	Chapter(const Chapter&);
	~Chapter();

	const Chapter& operator=(const Chapter&);
	bool operator==(const Chapter&) const;
	bool operator!=(const Chapter&) const;

	void setTitle(const char*); // TODO: implementare
	void setNumber(const int);	// TODO: implementare
	void setChapter(const char*, const int);

	const char* getTitle()	const { return title; }
	int getNumber()			const { return number; }
};

