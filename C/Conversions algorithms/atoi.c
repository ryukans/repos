#include <stdio.h>
#define LIMIT 1024

void getline(
    char v[],
    int lim
);

int atoi(
    char v[]
);


int main()
{
	char v[LIMIT], ch;
	int n;

	printf("Type number\n> ");
	getline(v, LIMIT);
	n = atoi(v);
	printf("\nConverted\n> %d\n", n);

	return 0;
}


/* getline: get line into v */
void getline(char v[], int lim)
{
    int ch, i;

    i = 0;
    while (--lim > 0 && (ch = getchar()) != '\x0a')
        v[i++] = ch;
    v[i] = '\0';
}


/* atoi: convert ASCII string into integer number and return it */
int atoi(char v[])
{
    int i, n, neg;

	n = neg = 0;

	for (i = 0; isspace(v[i]); ++i); /* skip white space */

	neg = v[i] == '-' ? 1 : 0;
	if (v[i] == '+' || v[i] == '-')
		++i;

    while (v[i] != '\0') {
        n = n * 10 + v[i] - '0';
        ++i;
    }
    neg ? n = -n : n;

    return n;
}












