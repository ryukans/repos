#include <stdio.h>
#include <conio.h>

int main()
{
    char line[10];
    char c;
    int i;

    for(i = 0; i < 10 && (c = getche()) != '\n'; i++)
        line[i] = c;

    putchar('\n');

    system("pause");

    return 0;
}
