
// p.72

#include <stdio.h>

#define MAXLINE 100

/* rudimentary calculator */
main()
{
	double sum, atof(char []);
	char line[MAXLINE];
	int getline(char line[], int max);

	sum = 0;
	while (getline(line, MAXLINE) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}

int getline(char s[], int lim)
{
	int ch, i;

	i = 0;
	while(--lim > 0 && (ch = getchar()) != EOF && ch != '\n')
		s[i++] = ch;

	if (s[i] == '\n')
		s[i++] = ch;

	s[i] = '\0';

	return i;
}
