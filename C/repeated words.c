#include <stdio.h>
#include <string.h>

#define MAXSIZE 100
#define OUT 0
#define IN 1


int getline(
    char s[],
    int size
);

void copy(
    char to[],
    char from[]
);


int main()
{
    char current[MAXSIZE], previous[MAXSIZE] = "";
    int words = 0;

    while (getline(current, MAXSIZE)) {
        ++words;
        if (strcmp(current, previous) == 0)
            printf("\tWord number %d is repeated: %s\n", words, current);
        copy(previous, current);
    }

    return 0;
}

int getline(char s[], int size)
{
    int ch, i = 0;
    int state = OUT;

    while (--size > 0 && (ch = getchar()) != EOF && !(state == IN && (ch == '\n' || ch == ' ' || ch == '\t'))) {
        if (ch != ' ' && ch != '\t' && ch != '\n') {
            state = IN;
            s[i++] = ch;
        }
        /*else if (state == IN && (ch == '\n' || ch == ' ' || ch == '\t'))
            break;*/
    }

    s[i] = '\0';

    return i;
}


void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}


