#include <stdio.h>
#include <string.h>
#include <limits.h>
#define ABS(x) ((x) < 0 ? -(x) : (x))
#define MAXSIZE 100

void itoa(
	int n,
	char s[]
);

int main()
{
	char s[MAXSIZE];

	itoa(INT_MIN, s); //-2147483648

	printf("%s\n", s);
	getch();

	return 0;
}


/* itoa: convert n to characters in s */
void itoa(int n, char s[])
{
	int i, sign;

    sign = n;
    i = 0;
	do {		/*generate digits in reverse order */
		s[i++] = ABS(n % 10) + '0';	 /* get next digit */
	} while ((n /= 10) < 0);	 /* delete it */

	if (sign < 0)
		s[i++] = '-';
    s[i] = '\0';

	strrev(s);
}




