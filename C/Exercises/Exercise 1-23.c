#include <stdio.h>
#define MAXSIZE 100

/// hello /*delete me*/ world printf("/*don't delete me*/"); /*"delete me"*/

int main()
{
    int c, d;

    while((c = getchar()) != EOF){
        if(c == '/' && (d = getchar()) == '*'){
            while(c != '*' && (d = getchar()) != '/');

            c = getchar();
        }
        else if(c == '"'){
            putchar(c); /* Print out the double quotation mark */
            while((c = getchar()) != '"')
                putchar(c);
        }
        else if(c == '/' && d == '/'){
            while((c = getchar()) != '\n');
            putchar('\n');
        }

        putchar(c);
    }

    return 0;
}
