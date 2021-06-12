#include "Piano.h"

Piano::Piano()
{
	piano[0].set_key("Do", 1);
	piano[1].set_key("Re", 2);
	piano[2].set_key("Mi", 3);
	piano[3].set_key("Fa", 4);
	piano[4].set_key("Sol", 5);
	piano[5].set_key("La", 6);
	piano[6].set_key("Si", 7);

	/*
	p.push_back(Key("Do", 1));
	p.push_back(Key("Re", 2));
	p.push_back(Key("Mi", 3));
	p.push_back(Key("Fa", 4));
	p.push_back(Key("Sol", 5));
	p.push_back(Key("La", 6));
	p.push_back(Key("Si", 7));*/

}

void Piano::play()
{

}

ostream& operator<<(ostream& out, const Piano& _this)
{
	for (int i = 0; i < Piano::KEYS; i++)
		out << " | " << _this.piano[i] << " | ";
	
	return out;
}
