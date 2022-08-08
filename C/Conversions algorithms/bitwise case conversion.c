#include <stdio.h>
#define MASK 0x20

void toupper(char *c);

void tolower(char *c);

int main()
{
	char x, y;

	x = 'F';
	y = 'f';

	printf("%c -- %c\n", x, y);

	toupper(y);
	tolower(x);

	printf("%c -- %c\n", x, y);

	return 0;
}


void toupper(char *c)
{
	*c ^= MASK;
}

void tolower(char *c)
{
	*c |= MASK;
}


