#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
enum boolean{FALSE, TRUE
};

void strcat(char s[], char t[]);
void get_line(char line[]);

int main()
{
	char input_line_1[MAXSIZE], input_line_2[MAXSIZE];

	printf("Type former string\n>");
	get_line(input_line_1);

	printf("Type latter string\n>");
	get_line(input_line_2);

	strcat(input_line_1, input_line_2);
	printf("%s", input_line_1);

	return EXIT_SUCCESS;

}


/* strcat: concatenate t to end of s; s must be big enough */
void strcat(char s[], char t[])
{
	int i, j;

	i = j = 0;
	while (s[i] != '\0')	/* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0')	/* copy t */
		;
}

void get_line(char line[])
{
	int i = 0;
	char c;

	while(i < MAXSIZE && (c = getchar()) != '\n')
		line[i++] = c;

	line[i] = '\0';
}

