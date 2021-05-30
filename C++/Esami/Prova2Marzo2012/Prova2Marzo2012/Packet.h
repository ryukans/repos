#pragma once
#include <iostream>
#include <cstring>

using std::istream;
using std::ostream;
using std::endl;

class Packet
{
	friend istream& operator>>(istream&, Packet&);
	friend ostream& operator<<(ostream&, const Packet&);

private:
	char* recipient;
	float weight;
	char* shape;

public:
	Packet();
	Packet(const char*, const float, const char*);
	Packet(const Packet&);
	~Packet();

	const Packet& operator=(const Packet&);
	bool operator==(const Packet&) const;
	bool operator!=(const Packet&) const;


	const char* getRecipient() const { return recipient; }
	const float getWeight() const { return weight; }
	const char* getShape() const { return shape; }

	void setRecipient(const char*);
	void setWeight(const float);
	void setShape(const char*);
};

