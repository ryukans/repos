#pragma once
#include <iostream>
#include <string.h>
#include <cstring>

using namespace std;

const int max_info_len = 100;

class Entry {

	friend	istream& operator >> (istream& in, Entry& e)		{	return e.setEntry(in);	}
	friend	ostream& operator << (ostream& out, const Entry& e) {	return e.getEntry(out); }

 public:
					 Entry();
					 Entry(const int, const char*);
					 Entry(const Entry& e)						{	*this = e;		}
					 ~Entry()									{	delete[] info;	}


	const	Entry&	 operator =	 (const Entry&);
			bool	 operator == (const Entry& e) const			{	return	((this->key == e.key) && (strcmp(this->info, e.info) == 0));	} // l'utilizzo di this-> è ridondante
			bool	 operator != (const Entry& e) const			{	return !(*this == e);													}
			bool	 operator >	 (const Entry& e) const			{	return	(this->key > e.key);											} // l'utilizzo di this-> è ridondante
			bool	 operator <	 (const Entry& e) const			{	return !(*this > e);													}
			bool	 operator >= (const Entry& e) const			{	return	((*this > e) && (*this == e));									} // *this == e potrebbe essere ridondante 
			bool	 operator <= (const Entry& e) const			{	return !(*this >= e);													}


			void	 setEntry(const int, const char*);

protected:
			istream& setEntry(istream&);
			ostream& getEntry(ostream&) const;


private:
	int		key;
	char*	info;
};
