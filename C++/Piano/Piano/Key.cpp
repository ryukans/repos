#include "Key.h"

Key::Key(const string& note, const float frequency)
{
	set_key(note, frequency);
}

void Key::set_key(const string& note, const float frequency)
{
	set_note(note);
	set_frequency(frequency);
}

void Key::set_note(const string& _note)
{
	if (!_note.length()) {
		note = "MISSING NOTE";
		return;
	}

	note = _note;
}

void Key::set_frequency(const float _frequency)
{
	if (_frequency <= 0.0f) {
		//TODO: set a default value
		return;
	}

	frequency = _frequency;
}

ostream& operator<<(ostream& out, const Key& _this) {
	return out << _this.note;
}
