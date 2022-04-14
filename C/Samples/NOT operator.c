#include <stdio.h>

int main()
{
    int x;

    x = 1;

    printf("Variable value: %d\n%s%s", x,
           x ? "true\n" : "false\n",
           !x ? "true\n" : "false\n");

    x = 0;

    printf("Variable value: %d\n%s%s", x,
           x ? "true\n" : "false\n",
           !x ? "true\n" : "false\n");

    /// Same statement without identation: printf("Variable value: %d\n%s%s", x, x ? "true\n" : "false\n", !x ? "true\n" : "false\n");




    return 0;
}
