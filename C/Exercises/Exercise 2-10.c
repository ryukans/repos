#include <stdio.h>

int lower(
    int c
);

int main()
{
    int c = 'F';

    printf(">%2c\n", tolower(c));

    system("pause");

	return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
	return c = (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
