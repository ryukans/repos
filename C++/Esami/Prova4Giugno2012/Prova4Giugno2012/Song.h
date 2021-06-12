#pragma once
#include "MultimediaFile.h"

class Song : public MultimediaFile
{
	friend istream& operator>>(istream& in, Song& _this) { return _this.set(in); }
	friend ostream& operator<<(ostream& out, const Song& _this) { return _this.get(out); }

private:
	char* title;
	char* artist;
	float time;

protected:
	virtual istream& set(istream&);
	virtual ostream& get(ostream&) const;

public:
	Song();
	Song(const char*, const int, const char*, const char*, const char*, const float);
	Song(const Song&);
	virtual ~Song();

	const Song& operator=(const Song&);
	bool operator==(const Song&) const;
	bool operator!=(const Song&) const;

	void setTitle(const char*);
	void setArtist(const char*);
	void setTime(const float);
};

