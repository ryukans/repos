#pragma once
#include "MultimediaFile.h"

class Video : public MultimediaFile
{
	inline friend istream& operator>>(istream& in, Video& _this) { return _this.set(in); }
	inline friend ostream& operator<<(ostream& out, const Video& _this) { return _this.get(out); }

private:
	char* author;
	char* context;
	char* date; // TODO create Data class

protected:
	virtual istream& set(istream&);
	virtual ostream& get(ostream&) const;

public:
	Video();
	Video(const char*, const int, const char*, const char*, const char*, const char*);
	Video(const Video&);
	virtual ~Video();

	const Video& operator=(const Video&);
	bool operator==(const Video&) const;
	bool operator!=(const Video&) const;

	void setAuthor(const char*);
	void setContext(const char*);
	void setDate(const char*);


};
