#include <stdio.h>
#define MAXSIZE 5

void getline(char line[], int maxline);

int main()
{
    char line[MAXSIZE];

    getline(line, MAXSIZE);
    printf("\n%s\n", line);

    return 0;
}


void getline(char s[], int lim)
{
    int c, i;

    for(i=0; i<lim-1 && (c=getchar())!=EOF; ++i)
        s[i] = c;
    if(c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
}

