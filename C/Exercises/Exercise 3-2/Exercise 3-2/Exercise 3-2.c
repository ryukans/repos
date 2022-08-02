/* Exercise 3-2 p. 60 */
#include <stdio.h>
#define MAXSIZE 50

void escape(
	char s[],
	char t[]
);

void getline(
	char s[]
);


int main()
{
	char s[MAXSIZE], t[MAXSIZE];
	int c, i;
	
	printf("Enter string> ");
	getline(s);
	system("cls");

	escape(s, t);
	printf("Original string: %s\nConverterd: %s\n\n",
		s, t);

	getch();

	return 0;
}


void escape(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i]) {
		switch (s[i]) {
		case '\n': {
			t[j++] = '\\';
			t[j++] = 'n';
			break;
		}
		case '\t': {
			t[j++] = '\\';
			t[j++] = 't';
			break;
		}
		case '\b': {
			t[j++] = '\\';
			t[j++] = 'b';
			break;
		}
		case '\a': {
			t[j++] = '\\';
			t[j++] = 'a';
			break;
		}
		case '\f': {
			t[j++] = '\\';
			t[j++] = 'f';
			break;
		}
		case '\r': {
			t[j++] = '\\';
			t[j++] = 'r';
			break;
		}
		case '\v': {
			t[j++] = '\\';
			t[j++] = 'v';
			break;
		}
		default:
			t[j++] = s[i];
			break;
		}
		++i;
	}
	t[j] = '\0';
}


void getline(char s[])
{
	int c, i;

	i = 0;
	for (i = 0; (c = getchar()) != EOF; i++)
		s[i] = c;
	s[i] = '\0';
}