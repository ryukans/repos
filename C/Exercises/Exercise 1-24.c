#include <stdio.h>
#define NO_ERROR 0
#define SC_ERROR -1
#define PAR_ERROR -2
#define BRCKT_ERROR -3
#define BRAC_ERROR -4
#define SQ_ERROR -5
#define DQ_ERROR -6

void echo_error(
    int error_msg
);

int main()
{
    int c, d, status = NO_ERROR;
    while((c = getchar()) != EOF){
        if(c != ';' && (d = getchar()) == '\n')
            echo_error(SC_ERROR);
        else if(c == '(')
            while((c = getchar()) != '\n')
                if(c != ')')
                    echo_error(PAR_ERROR);
    }
}


void echo_error(int error_msg)
{
    switch(error_msg){
        case SC_ERROR:
            printf("Syntax error ! A semicolon is missed\n");
            break;
        case PAR_ERROR:
            printf("Syntax error ! A parenthesis is missed\n");
            break;
        case BRCKT_ERROR:
            printf("Syntax error ! A bracket is missed\n");
            break;
        case BRAC_ERROR:
            printf("Syntax error ! A braces is missed\n");
            break;
        case SQ_ERROR:
            printf("Syntax error ! A single quite is missed\n");
            break;
        case DQ_ERROR:
            printf("Syntax error ! A double quote is missed\n");
            break;
        case NO_ERROR:
            NULL;
            break;
    }
}



