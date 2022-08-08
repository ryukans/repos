/*
	Name: reverse v2.0
	Copyright: None
	Author: Claudio Pisa
	Date: 06/09/16 22:29
	Latest modify date: 09/07/2017 18:06
	Description: The program reverses a string.
	The program doesn't uses any built-in functions, such as 'strlen'.
	The difference between this version and the earlier one is that
	now the program reverse each character stored into the array.
*/

#include <stdio.h>
#define MAXCHARS 100

void reverse(
    char s[]
);

void getline(
    char s[],
    int size
);

int getlen(
    char s[]
);

int main()
{

	char line[MAXCHARS];
	int i;

	printf("Type string:\t");
	getline(line, MAXCHARS);

	reverse(line);
	printf("\nReversed:\t%s\n", line);

	return 0;
}


int getlen(char s[])
{
    int i;

	i = 0;
	while (s[i])
		i++;

	return i;

}


void reverse(char s[])
{
    int i, j, temp;

	for (i = 0, j = getlen(s)-1; i < j; i++, j--) {
        temp = s[i], s[i] = s[j], s[j] = temp;
       /// printf("\ni:%d-%c j:%d-%c\n", i, s[i], j, s[j]);
    }
}


void getline(char s[], int n)
{
    int c, i;

    for (i = 0; i < n && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    s[i] = '\0';
}



