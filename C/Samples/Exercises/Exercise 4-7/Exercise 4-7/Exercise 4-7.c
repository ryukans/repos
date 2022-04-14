#include <stdio.h>

#define BUFSIZE 100
int getch(void);
void ungetch(int);
void ungets(char[]);


int main()
{
	char s[] = "Test string\n";
	int c;

	ungets(s);
	while ((c = getch()) != EOF)
		putchar(c);

	return 0;
}

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}


void ungets(char s[])
{
	int i = strlen(s);

	while (i > 0)
		ungetch(s[--i]);
}