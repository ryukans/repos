#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

int main()
{
    char s[MAXSIZE];

    itoa(125, s, 5);
    printf("%s\n", s);
    getch();

	return 0;
}


void itoa(int n, char s[], int b)
{
	int i, sign;

	if((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign < 0)
		s[i++] = '-';

	while (i < b)
		s[i++] = ' ';

    s[i] = '\0';

	strrev(s);
}
