#include <stdio.h>
#include <stdlib.h>

int atoi(
	char s[]
);


int main()
{
	char s[] = "255";
	int n = atoi(s);

	printf("%d\n", n);

	return 0;
}


/* atoi: convert string s to integer using atof */
int atoi(char s[])
{
	return (int) atof(s);
}

