#include "Song.h"

istream& Song::set(istream& in)
{
	MultimediaFile::set(in);

	char buffer[100] = "";

	in.getline(buffer, 100);
	setTitle(buffer);

	in.ignore();

	in.getline(buffer, 100);
	setArtist(buffer);

	float time = 0.0f;
	in >> time;
	setTime(time);

	return in;
}

ostream& Song::get(ostream& out) const 
{
	MultimediaFile::get(out);

	return	out	 << "Title: " << title
					<< "\nArtist: " << artist
						<< "\nDurate: " << time
							<< std::endl;
}

Song::Song() : MultimediaFile(), title(new char[1]), artist(new char[1]), time(0.0f)
{
	strcpy_s(title, 1, "");
	strcpy_s(artist, 1, "");
}

Song::Song(const char* url, const int kbyte, const char* type, const char* title, const char* artist, const float time)
	: MultimediaFile(url, kbyte, type)
{
	setTitle(title);
	setArtist(artist);
	setTime(time);
}

Song::Song(const Song& other)
	: MultimediaFile(other)
{
	setTitle(other.title);
	setArtist(other.artist);
	setTime(other.time);
}

Song::~Song()
{
	delete[] title;
	delete[] artist;
}

const Song& Song::operator=(const Song& other)
{
	if (this != &other) {
		MultimediaFile::operator=(other);
		setTitle(other.title);
		setArtist(other.artist);
		setTime(other.time);
	}

	return *this;
}

bool Song::operator==(const Song& other) const {
	return	MultimediaFile::operator==(other) 
			&& !strcmp(title, other.title) 
			&& !strcmp(artist, other.artist)
			&& (time == other.time);
}

bool Song::operator!=(const Song& other) const {
	return !(*this == other);
}

void Song::setTitle(const char* _title)
{
	const int len = strlen(_title);

	delete[] title;
	title = new char[len + 1];
	len != 0 ? strcpy_s(title, len + 1, _title) : strcpy_s(title, len + 1, "");
}

void Song::setArtist(const char* _artist)
{
	const int len = strlen(_artist);

	delete[] artist;
	artist = new char[len + 1];
	len != 0 ? strcpy_s(artist, len + 1, _artist) : strcpy_s(artist, len + 1, "");
}

void Song::setTime(const float _time)
{
	if (_time < 0)
		return;

	time = _time;
}
