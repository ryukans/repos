#include "Packet.h"

Packet::Packet() : recipient(new char[1]), weight(0.0f), shape(new char[1])
{
	strcpy_s(recipient, 1, "");
	strcpy_s(shape, 1, "");
}

Packet::Packet(const char* recipient, const float weight, const char* shape)
{
	setRecipient(recipient);
	setWeight(weight);
	setShape(shape);
}

Packet::Packet(const Packet& other)
{
	setRecipient(other.recipient);
	setWeight(other.weight);
	setShape(other.shape);
}

Packet::~Packet()
{
	delete[] recipient;
	delete[] shape;
}

const Packet& Packet::operator=(const Packet& other)
{
	if (this != &other) {
		setRecipient(other.recipient);
		setWeight(other.weight);
		setShape(other.shape);
	}

	return *this;
}

bool Packet::operator==(const Packet& other) const {
	return !strcmp(recipient, other.recipient) && (weight == other.weight) && !strcmp(shape, other.shape);
}

bool Packet::operator!=(const Packet& other) const {
	return !(*this == other);
}

void Packet::setRecipient(const char* _recipient)
{
	const int len = strlen(_recipient);

	if (len == 0) 
		return;
	
	delete[] recipient;
	recipient = new char[len + 1];
	strcpy_s(recipient, len + 1, _recipient);
}

void Packet::setWeight(const float _weight)
{
	if (_weight < 0.0f)
		return;

	weight = _weight;
}

void Packet::setShape(const char* _shape)
{
	const int len = strlen(_shape);

	if (len == 0)
		return;

	delete[] shape;
	shape = new char[len + 1];
	strcpy_s(shape, len + 1, _shape);
}


istream& operator>>(istream& in, Packet& _this)
{
	char buffer[100];

	in.getline(buffer, 100);
	_this.setRecipient(buffer);

	float weight = 0.0f;
	in >> weight;
	_this.setWeight(weight);

	in.ignore();

	in.getline(buffer, 100);
	_this.setShape(buffer);

	return in;
}


ostream& operator<<(ostream& out, const Packet& _this) {
	return	out	<< "Recipient: " << _this.recipient 
					<< "\nWeight: " << _this.weight 
						<< "\nShape: " << _this.shape 
							<< endl;
}

