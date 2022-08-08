/* page 69 */
#include <stdio.h>
#define MAXLINE 1000	/* maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char s[], char t[]);

char pattern[] = "would";	/* pattern to search for */


/* find all lines matching pattern */
main()
{
	char line[MAXLINE];
	int found = 0;

	while (getline(line, MAXLINE) > 0) {
        int index = strindex(line, pattern);
        if (index >= 0) {
			printf("%s\nbegins at: %d\n", line, index);
			found++;
		}
	}
	return found;
}


/* getline: get line into s, return length */
int getline(char s[], int lim)
{
	int c, i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}


/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k, rmi = -1;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			rmi = i;
	}
	return rmi;
}



int strrindex(char s[], char t[])
{
	int i, j, k;

	for (i = strlen(s) - strlen(t); i >= 0; i--) {
		for (j = i, k = 0; t[k] != '\0' && s[j]==t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

"aaZ"
"aaZZaaaZZaaZa"

