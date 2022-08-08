// p. 34
#include <stdio.h>
#define MAXSIZE 500
#define MAXLINE 10
#define NO_GAPS -1

void getline(char []);

int main()
{
    char line[MAXSIZE], formatted[MAXSIZE];
    int i, j, size_line, count, gap_index;

    while(1){
        printf("Type\n> ");
        getline(line);

        gap_index = NO_GAPS;
        size_line = 0;

        for(i = j = 0, count = 0; line[i] != '\0'; ++i, ++count){//a supercalifraginistimistiralitoso
            if(gap_index != NO_GAPS)
                ++size_line;

            if(line[i] == ' '){
                gap_index = i;
                size_line = 0;
            }

            if(size_line+count > MAXLINE){
                if(gap_index != NO_GAPS){
                    formatted[gap_index] = '\n';
                    gap_index = NO_GAPS;
                }
                else{
                    formatted[j++] = '-';
                    formatted[j++] = '\n';

                }
                count = 0;
            }

            formatted[j++] = line[i];
        }

        formatted[j] = '\0';
        printf("\n%s\n", formatted);

        if(getch() == 0x1b){
            printf("End");
            break;
        }
        else
            putchar('\n');
    }

    return 0;
}


void getline(char s[])
{
    char c;
    int i;

    for(i = 0; i < MAXSIZE && (c = getchar()) != '\n'; ++i)
        s[i] = c;

    s[i] = '\0';

}


   /* getline(s);

    blank_index = -1;
    i = count = 0;
    while(s[i] != '\0'){
        if(s[i] == ' ' || s[i] == '\t')
            blank_index = i;

        ++count;

        if(count > MAXLINE)
            if(blank_index != -1){
                if(blank_index < MAXLINE)
                    s[blank_index] = '\n';
                else
                    blank_index = -1;
            }
        ++i;
    }

    if(blank_index != -1)
        printf("%s", s);
    else
        for(i = 0, count = 0; s[i] != '\0'; ++i, ++count){
            if(count > MAXLINE)
                printf("-\n");
            else
                putchar(s[i]);
        } */
