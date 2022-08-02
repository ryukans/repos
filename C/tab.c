#include <stdio.h>
#define TABSIZE 8

int main()
{
    int c, nb, pos;

    nb = 0;
    pos = 0;
    while((c = getchar()) != EOF){
        if(c == '\t'){
            nb = TABSIZE - pos % TABSIZE;
            while(nb--){
                putchar(' ');
            }
            pos = 0;
        }
        else if(c == '\n'){
            putchar(c);
            pos = 0;
        }
        else{
            putchar(c);
            ++pos;
        }
    }

    return 0;
}
