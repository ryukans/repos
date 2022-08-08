#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 150

void getline(char []);
int string_cmp(char [], char []);
int cmp_string(char *, char *); /* Same as string_cmp but with pointers */
int compare_strings(char [], char []); /* Source: http://www.programmingsimplified.com/c-program-compare-two-strings */

int main()
{

	char former[MAXSIZE], latter[MAXSIZE], ch;
	int i;

	printf("Type former string\n> ");
	getline(former);

    printf("Type latter string\n> ");
    getline(latter);

	if(!string_cmp(former, latter)) /* return 0: string are equals; return -1: strings are not equals */
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;

}


void getline(char s[])
{
    char ch;
    int i;

    for(i = 0; i < MAXSIZE && (ch = getchar()) != '\n'; i++)
        s[i] = ch;

    if(ch == '\n')
        s[i++] = '\n';

    s[i] = '\0';

}


int string_cmp(char s1[], char s2[])
{

	int i = 0;
	while(s1[i] != '\0'){
	    if(s1[i] == s2[i])
            ++i;
        else
            return -1;
	}

	return 0;

}


int cmp_string(char *s1, char *s2)
{

	int i = 0;
	while(*s1 != '\0') {
        if(*s1 == *s2) {
            ++s1;
            ++s2;
        }
        else
            return -1;
	}

	return 0;

}


int compare_strings(char a[], char b[])
{

   int c = 0;

   while (a[c] == b[c]) {
      if (a[c] == '\0' || b[c] == '\0')
         break;
      c++;
   }

   if (a[c] == '\0' && b[c] == '\0')
      return 0;
   else
      return -1;

}
