#include "Chapter.h"


Chapter::Chapter() : title(new char[1]), number(0) {
	strcpy_s(title, 1, "");
}

Chapter::Chapter(const char* _title, const int number) : title(new char[strlen(_title)+1]), number(number) {
	strcpy_s(title, strlen(_title)+1, _title);
}

Chapter::Chapter(const Chapter& C) : title(new char[strlen(C.title) + 1]), number(C.number) {
	strcpy_s(title, strlen(C.title) + 1, C.title);
}

Chapter::~Chapter() {
	delete[] title;
}

const Chapter& Chapter::operator=(const Chapter& C)
{
	if (this != &C) {
		delete[] title;
		int len = strlen(C.title) + 1;
		title = new char[len];
		strcpy_s(title, len, C.title);
		number = C.number;
	}

	return *this;
}

void Chapter::setChapter(const char* _title, const int _number)
{
	delete[] title;
	int len = strlen(_title) + 1;
	title = new char[len];
	strcpy_s(title, len, _title);
	number = _number;
}

bool Chapter::operator==(const Chapter& C) const {
	return !strcmp(title, C.title) && (number == C.number);
}

bool Chapter::operator!=(const Chapter& C) const {
	return !(*this==C);
}

ostream& operator<<(ostream& out, const Chapter& C) {
	return out << C.number << " " << C.title << std::endl;
}

