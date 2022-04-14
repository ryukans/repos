#include <stdio.h>
#define TABSIZE 8

int main()
{
    int c; /* Take characters in input */
    int i; /* Counter for cycles */
    int chars = 0; /* Counter of the characters */
    int nb = 0; /* Counter of blanks */
    int cb = 0; /* Calculated number of blanks equals to a tab */

    while((c = getchar()) != EOF){
        nb = 0;
        if(c != ' ' && c != '\n')
            ++chars;
        cb = TABSIZE - chars % TABSIZE;
        if(c == ' '){
            ++nb;
            while((c = getchar()) == ' ')
                ++nb;
            if(cb == nb){
                putchar('\t');
                chars = 0;
            }
            else if(cb < nb){
                putchar('\t');
                for(i = nb-cb; i > 0; --i)
                    putchar(' ');
                chars = 0;
            }
            else if(cb > nb){
                for(i = nb; i > 0; --i)
                    putchar(' ');
                chars = 0;
            }
            putchar(c);
        }
        else
            putchar(c);
    }





    return 0;
}
