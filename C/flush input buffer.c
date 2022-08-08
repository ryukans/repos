#include <stdio.h>

int main()
{
    char c, d;

    printf("Do you have a Fever? y/n\n");

    c = getchar();
    flush();
    printf("%d\n", c);


    printf("Do you have a runny nose or cough? y/n\n");

    d = getchar();
    flush();
    printf("%d\n", d);

    return 0;
}


void flush()
{
    int c;

    while((c = getchar()) != EOF && c != '\n');
}

