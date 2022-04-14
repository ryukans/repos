#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024

void clear(void);
void getline(
    char s[],
    int size
);
void squeeze(
    char s1[],
    char s2[]
);
int is_in(
    char c,
    char line[]
);

int main()
{
    char line[MAXSIZE], blacklist[MAXSIZE];

    printf("Type string\n> ");
    getline(line, MAXSIZE);

    clear();

    printf("What character\s from \"%s\" do you want to delete ?\n> ", line);
    getline(blacklist, MAXSIZE);

    clear();

    squeeze(line, blacklist);
    printf("String> %s\n", line);

    getch();

    return 0;
}


void getline(char s[], int size)
{
    int c, i;

    for(i = 0; i < size && (c = getchar()) != '\n'; ++i)
        s[i] = c;

    s[i] = '\0';
}


void squeeze(char s1[], char s2[])
{
    int i, j;

    i = j = 0;
    while(s1[i] != '\0'){
        if(is_in(s1[i], s2)){
            s1[j] = s1[i];
            ++j;
        }
        ++i;
    }
    s1[j] = '\0';
}


int is_in(char c, char s[])
{
    int i;

    i = 0;
    while(s[i] != '\0'){
        if(c == s[i])
            return 0;
        else
            ++i;
    }
    return 1;
}


void clear()
{
	#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
		system("clear");
	#endif

	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}




