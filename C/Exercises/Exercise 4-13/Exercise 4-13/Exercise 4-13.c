#include <stdio.h>
#include <string.h>

void reverse(
	char s[]
);

void reverse2(
	char s[]
);


int main()
{
	char s[] = "reverse me";
	char s2[] = "abcd";

	reverse(s);
	reverse2(s2);
	printf("%s\n%s\n", s, s2);

	getch();

	return 0;
}

/* my versions: */

void reverse(char s[])
{
	static int i;
	int tmp;
	int j = (strlen(s) - 1) - i;

	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
	++i;

	if (i < j)
		reverse(s);
}


void reverse2(char s[])
{
	void reverse_recursive(
		char s[],
		int i,
		int length
	);

	reverse_recursive(s, 0, strlen(s)-1);
}

void reverse_recursive(char s[], int i, int len)
{
	int j = len;
	int tmp;

	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;

	if (i < j)
		reverse_recursive(s, ++i, --j);
}



/* alternative ways: 

void reverse(char s[])
{
	void reverser(
		char s[],
		int i,
		int len
	);

	reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len)
{
	int c, j;

	j = len - (i + 1);
	if (i < j) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		reverser(s, ++i, len);
	}
}

*/



