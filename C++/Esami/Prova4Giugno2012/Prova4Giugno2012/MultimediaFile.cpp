#include "MultimediaFile.h"
#include <cstring>


istream& MultimediaFile::set(istream& in)
{
	char buffer[100] = "";
	in.getline(buffer, 100);
	setUrl(url);
	
	int kbyte = 0;
	in >> kbyte;
	setKbyte(kbyte);

	in.ignore();

	in.getline(buffer, 10);
	setType(buffer);

	return in;
}

ostream& MultimediaFile::get(ostream& out) const {
	return	out	 << "Url: " << url
					<< "\nKbyte: " << kbyte
						<< "\nType: " << type
							<< std::endl;		
}

MultimediaFile::MultimediaFile() : url(new char[1]), kbyte(0), type(new char[1])
{
	strcpy_s(url, 1, "");
	strcpy_s(type, 1, "");
}

MultimediaFile::MultimediaFile(const char* url, const int kbyte, const char* type)
{
	setUrl(url);
	setKbyte(kbyte);
	setType(type);
}

MultimediaFile::MultimediaFile(const MultimediaFile& other)
{
	setUrl(other.url);
	setKbyte(other.kbyte);
	setType(other.type);
}

MultimediaFile::~MultimediaFile()
{
	delete[] url;
	delete[] type;
}

const MultimediaFile& MultimediaFile::operator=(const MultimediaFile& other)
{
	if (this != &other) {
		setUrl(other.url);
		setKbyte(other.kbyte);
		setType(other.type);
	}
	
	return *this;
}

bool MultimediaFile::operator==(const MultimediaFile& other) const {
	return !strcmp(url, other.url) && (kbyte == other.kbyte) && !strcmp(type, other.type);
}

bool MultimediaFile::operator!=(const MultimediaFile& other) const {
	return !(*this == other);
}

void MultimediaFile::setUrl(const char* _url)
{
	const int len = strlen(_url);

	if (len == 0)
		return;

	delete[] url;
	url = new char[len + 1];
	strcpy_s(url, len + 1, _url);
}

void MultimediaFile::setKbyte(const int _kbyte)
{
	if (_kbyte < 0)
		return;

	kbyte = _kbyte;
}

void MultimediaFile::setType(const char* _type)
{
	const int len = strlen(_type);
	
	if (len == 0)
		return;
	/*
	char temp[] = ".";

	strcpy_s(temp, len + 1, _type);*/

	delete[] type;
	type = new char[len + 1];
	strcpy_s(type, len + 1, _type);
	//strcpy_s(type, strlen(temp)+1, temp);
}









