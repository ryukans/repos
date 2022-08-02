#include <stdio.h>
#define MAXLINE 1000

int main()
{
    char line[MAXLINE];
    int i;
    int c;

    putchar('>');
    getline(line);

    i = 0;
    while(line[i] != '\n')
        ++i;

    printf("Newline at index: %d\n", i);

    return 0;
}


void getline(char s[])
{
    char c;
    int i;

    for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
/*
    if(c == '\n')
        s[i++] = '\n';
    s[i] = '\0'; */

    s[i++] = '\n';
    s[i] = '\0';
}

