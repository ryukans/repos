#include <stdio.h>

int main()
{
    /*
    signed range value: -128 to 127
    unsigned range value: 0 to 255
    By default, char is signed.
    */

    char a0 = 'A';
    signed a1 = 'A';
    unsigned a2 = 'A';

    printf("a0 = a1> %s\n", a0 == a1 ? "true" : "false");
    printf("a1 = a2> %s\n", a1 == a2 ? "true" : "false");
    printf("\nValue table\na0\ta1\ta2\n%d\t%d\t%d\n\n", a0, a1, a2);

    getch();
    system("cls");

    char b0 = 0xFF; /* Same as: char b0 = '\x0ff' */
    signed char b1 = 'A';
    unsigned char b2 = 0xFF;

    printf("b0 = b1> %s\n", b0 == b1 ? "true" : "false");
    printf("b1 = b2> %s\n", b1 == b2 ? "true" : "false");
    printf("\nValue table\nb0\tb1\tb2\n%d\t%d\t%d\n\n", b0, b1, b2);


}

