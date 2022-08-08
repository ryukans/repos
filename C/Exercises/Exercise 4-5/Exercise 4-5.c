#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'

/* function prototypes */
int getop(char []);
void push(double);
double pop(void);
double top(void);
void clear(void);
void mathcomm(char []);

/* reverse Polish calculator */
main()
{
    int type;
    double op1, op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathcomm(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if(op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '?':
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c':
            clear();
            break;
        case 'd':
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's':
            op2 = pop();
            op1 = pop();
            push(op2);
            push(op1);
            break;
        case '^':// 4 2 ^
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '\n' :
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}


void mathcomm(char s[])
{
    char comm[strlen(s)];
    int i;

    for (i = 0; i < strlen(s); ++i)
        comm[i] = tolower(s[i]);

    if (strcmp(comm, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(comm, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(comm, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(comm, "pow") == 0 || strcmp(comm, "power") == 0) {
        int exp = pop();
        push(pow(pop(), exp));
    }
    else
        printf("error: command \"%s\" is not supported\n", comm);
}

#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/*pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
        printf("error: stack empty\n");
    return 0.0;
}

void clear(void)
{
    sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[]) /* we pass s[] to getop to store input */
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    i = 0;

    if (isalpha(c)) {
        do {
            s[++i] = c = getch();
        } while(isalpha(c));

        s[i] = '\0';

        if (c != EOF)
            ungetch(c);

        if (strlen(s) > 1)
            return NAME;
        else
            return c;   /* it may be a command */
    }



    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */

    if (c == '-') {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c; /* collect next character, whether is a number or a decimal point */
        else {
            if (c != EOF)
                ungetch(c);

            return '-';
        }
    }


    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;

/* getch: the function which actually gets chars! */
int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back in input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
