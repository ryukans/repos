#include <stdio.h>
#include <string.h>
#define MAXSIZE 1024

void itob(
	int number,
	char line[],
	unsigned base
);

int main()
{
	int n;	/* number */
	int b;	/* base */
	char s[MAXSIZE];

	srand(time(0));

	for (n = rand() % 255 + 1, b = 2; b < 17; n = rand() % 255 + 1, b++) {
		itob(n, s, b);
		printf("(%d)10\t->\t(%s)%d\n\n", n, s, b);
	}

	getch();

	return 0;
}


void itob(int n, char s[], unsigned b)
{
	int i, sign;

	if ((sign = n) < 0)
		n = -n;

	i = 0;
	do {
		int tmp = n % b;
		s[i++] = (tmp <= 9) ? tmp + '0' : tmp + 'a' - 10;
	} while ((n /= b) > 0);

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';

	strrev(s);
}
