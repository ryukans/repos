#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define MAXVAR 26
#define NUMBER '0'
#define NAME 'n'

/* function prototypes */
int getop(char[]);
void push(double);
double pop(void);
void clear(void);
void mathcomm(char[]);

/* reverse Polish calculator */
main()
{
	int type, var = 0;
	double op1, op2, last;
	char s[MAXOP];
	double variable[MAXVAR];

	int i;
	for (i = 0; i < MAXVAR; ++i)
		variable[i] = 0.0;

	while ((type = getop(s)) != EOF) {
		switch (type) {
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
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push(fmod(pop(), op2));
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
		case '=':
			pop();
			if (isalpha(toupper(var)))
				variable[var - 'A'] = pop();
			break;
		case 'l':
			push(last);
			break;
		case '\n':
			last = pop();
			printf("\t%.8g\n", last);
			break;
		default:
			if (isalpha(toupper(type))) {
				push(variable[type - 'A']);
				var = type;
			}
			else
				printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}


void mathcomm(char comm[])
{
	int i;

	for (i = 0; i < strlen(comm); ++i)
		comm[i] = tolower(comm[i]);

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
		while (isalpha(s[++i] = c = getch()))
			;

		s[i] = '\0';

		if (c != EOF)
			ungetch(c);

		return (strlen(s) > 1) ? NAME : s[0];
	}

	if (!isdigit(c) && c != '.' && c != '-')
		return c;

	if (c == '-') {
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c; /* collect next character, whether it is a number or a decimal point */
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

int buf[BUFSIZE]; /* buffer for ungetch */
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
