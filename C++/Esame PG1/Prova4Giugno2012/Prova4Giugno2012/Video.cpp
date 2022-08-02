#include "Video.h"

istream& Video::set(istream& in)
{
	MultimediaFile::set(in);

	char buffer[100] = "";

	in.getline(buffer, 100);
	setAuthor(buffer);

	in.ignore();

	in.getline(buffer, 100);
	setContext(buffer);

	in.ignore();

	in.getline(buffer, 100);
	setDate(buffer);

	return in;
}

ostream& Video::get(ostream& out) const
{
	MultimediaFile::get(out);

	return	out	 << "Author: " << author
					<< "\nAbout: " << context
						<< "\nRecorded on: " << date
							<< std::endl;
}

Video::Video()
	: MultimediaFile(), author(new char[1]), context(new char[1]), date(new char[1])
{
	strcpy_s(author, 1, "");
	strcpy_s(context, 1, "");
	strcpy_s(date, 1, "");
}

Video::Video(const char* url, const int kbyte, const char* type, const char* author, const char* context, const char* date)
	: MultimediaFile(url, kbyte, type)
{
	setAuthor(author);
	setContext(context);
	setDate(date);
}

Video::Video(const Video& video)
	: MultimediaFile(video)
{
	setAuthor(video.author);
	setContext(video.context);
	setDate(video.date);
}

Video::~Video()
{
	delete[] author;
	delete[] context;
	delete[] date;
}

const Video& Video::operator=(const Video& other)
{
	if (this != &other) {
		MultimediaFile::operator=(other);
		setAuthor(other.author);
		setContext(other.context);
		setDate(other.date);
	}

	return *this;
}

bool Video::operator==(const Video& other) const {
	return	MultimediaFile::operator==(other)
			&& !strcmp(author, other.author)
			&& !strcmp(context, other.context)
			&& !strcmp(date, other.date);
}

bool Video::operator!=(const Video& other) const {
	return !(*this == other);
}

void Video::setAuthor(const char* _author)
{
	const int len = strlen(_author);

	delete[] author;
	author = new char[len + 1];
	len != 0 ? strcpy_s(author, len + 1, _author) : strcpy_s(author, len + 1, "");
}


void Video::setContext(const char* _context)
{
	const int len = strlen(_context);

	delete[] context;
	context = new char[len + 1];
	len != 0 ? strcpy_s(context, len + 1, _context) : strcpy_s(context, len + 1, "");
}

void Video::setDate(const char* _date)
{
	const int len = strlen(_date);

	delete[] date;
	date = new char[len + 1];
	len != 0 ? strcpy_s(date, len + 1, _date) : strcpy_s(date, len + 1, "");
}