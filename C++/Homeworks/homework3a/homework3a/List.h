#pragma once
#include "Entry.h"

const int maxdim = 100;

typedef Entry E;

class List {

	friend		ostream& operator << (ostream& out, const List& L)	{	return L.getList(out);	}
	friend		istream& operator >> (istream&	in, List& L)		{	return L.setList(in);	}

public:

	explicit			 List(int n = 1);
						 List(const E&);
						 List(const List&);
						 ~List();

	const		List&	 operator =	 (const List&);
				bool	 operator == (const List&)	const;
				bool	 operator != (const List&)	const;
				E&		 operator [] (int)			const throw (const char*);

				int		 getSize()									{	return size;			}
				int		 getNumElem()								{	return nelem;			}
				bool	 isFull()									{	return nelem == size;	}
				bool	 isEmpty()									{	return !isFull();		}
				void	 insert(const E&) throw (const char*);
				bool	 hasEntry(E&, int& pos);
				void	 setList(int) throw (const char*);
			
protected:
				istream& setList(istream&);
				ostream& getList(ostream&) const;



private:
	int size;	//Indica la capacità complessiva della lista
	int nelem;	//Indica il numero di elementi presenti nella lista
	E* list;
};
