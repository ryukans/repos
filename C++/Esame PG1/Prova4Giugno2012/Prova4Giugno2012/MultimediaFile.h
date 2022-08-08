#pragma once
#include <iostream>

using std::istream;
using std::ostream;

class MultimediaFile
{
	friend istream& operator>>(istream& in, MultimediaFile& _this) { return _this.set(in); }
	friend ostream& operator<<(ostream& out, const MultimediaFile& _this) { return _this.get(out); }

private:
	char* url;
	int kbyte;
	char* type;

protected:
	virtual istream& set(istream&);
	virtual ostream& get(ostream&) const;

public:
	MultimediaFile();
	MultimediaFile(const char*, const int, const char*);
	MultimediaFile(const MultimediaFile&);
	virtual ~MultimediaFile();

	const MultimediaFile& operator=(const MultimediaFile&);
	bool operator==(const MultimediaFile&) const;
	bool operator!=(const MultimediaFile&) const;

	void setUrl(const char*);
	void setKbyte(const int);
	void setType(const char*);
};
