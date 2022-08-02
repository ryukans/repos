/*
	Name: reverse v1.5
	Copyright: None
	Author: Claudio Pisa
	Date: 06/09/16 19:33
	Description: The program reverses a string.
	The program doesn't uses any built-in functions, such as 'strlen'.
*/

#include <stdio.h>
#define MAXSIZE 100

void reverse(char s[], int size);
int getsize(char s[]);

main()
{

	char line[MAXSIZE];
	int size;

	puts("Type string >: ");
	gets(line);
	size = getsize(line);
	reverse(line, size);

	return 0;
}

int getsize(char s[])
{

	int i;

	i = 0;
	while(s[i] != '\0')
		i++;

	return i;

}

void reverse(char s[], int size)
{

	int i;

	i = size-1;
	while(i >= 0)
		printf("%c", s[i--]);

}

