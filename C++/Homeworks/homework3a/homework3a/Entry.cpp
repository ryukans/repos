#include "Entry.h"

Entry::Entry()
{
	info = new char[1];
	strcpy_s(info, 1, "");
	key = 0;
}

Entry::Entry(const int key, const char* info)
{
	try
	{
		setEntry(key, info);
	}
	catch (const char* errmsg)
	{
		cerr << errmsg << endl;
	}
}

const Entry& Entry::operator=(const Entry& e)
{
	if (this != &e)
		setEntry(e.key, e.info);

	return *this;
}

void Entry::setEntry(const int key, const char* info)
{
	if (key < 0)
		throw "Error: bad key value\n";

	int new_info_len = strlen(info);
	if (new_info_len > max_info_len)
		throw "Error: out of range\n";

	//if (this->info != NULL)
	delete[] this->info;
	this->info = new char[new_info_len + 1];

	strcpy_s(this->info, new_info_len + 1, info);
	this->key = key;
}

istream& Entry::setEntry(istream& in)
{
	char buffer[max_info_len];
	int tmp_key;

	in.ignore();
	in.getline(buffer, max_info_len);
	in >> tmp_key;

	setEntry(tmp_key, buffer);

	return in;
}

ostream& Entry::getEntry(ostream& out) const
{
	out << key << ' ';
	strlen(info) == 0 ? out << "Empty voice\n" : out << info << endl;

	return out;
}



