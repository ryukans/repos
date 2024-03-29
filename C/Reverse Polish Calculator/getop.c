#include <stdio.h>
#include <ctype.h>
#include "getop.h"
#include "stackio.h"

#define NUMBER '0'

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;

	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c;		/* not a number */

	i = 0;
	if (isdigit(c)) {	/* collect integer part */
		do {
			s[++i] = c = getch();
		} while (isdigit(s[i]));
	}

	if (c == '.')		/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
}





