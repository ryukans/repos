#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 2048
#define PREFIX_SIZE 2
#define EMPTY -1
#define FULL 0

enum boolean { NO, YES };


void banner(void);
void clear(void);
void pause(
	char *__msg,
	int __in
);
void get_hex(
	char hex[]
);
unsigned long long htoi(
	char hex[]
);
int strlength(
	char s[]
);


int main()
{
	char hex[MAXSIZE];
	unsigned long long dec;

    banner();
    pause("\nPress any key to continue\n", YES);
    clear();

    while(1){
        printf("Hex>:\t");
        get_hex(hex);

        clear();

        printf("(%s)16 = (%lld)10\n", hex, dec = htoi(hex));

        pause("\n.Any key to continue\n.Esc to exit\n", NO);
        if(getch() == 0x1b){
            clear();
            break;
        }
        else
            clear();
    }

	return 0;
}

void get_hex(char hex[])
{
	unsigned int i;
	int prefix = EMPTY;
	char c;

    while(1){
        i = 0;
        while(i < MAXSIZE && (c = getchar()) != '\n'){
           if(prefix == EMPTY){
                if(c == '0' && ((c = getchar()) == 'x' || c == 'X')){
                    /* unreachable */
                    if(prefix == FULL){
                        pause("Invalid user input!\n\n"
                            "Too many prefixes or invalid prefix position\n"
                            "Any key to retry\n", YES);
                        clear();
                        i = 0;
                        prefix = EMPTY;
                    }

                    else{
                        hex[i++] = '0';
                        hex[i++] = c; /* -c- now is equal to 'x' or 'X' */
                        prefix = FULL;
                        c = getchar(); /* Get the next char in the input buffer */
                    }
                }
           }
           if(isdigit(c) || ((c >= 'A' || c >= 'a') && (c <= 'F' || c <= 'f')) || (c == ':' || c == '.')){
                hex[i++] = c;
                prefix = FULL;
           }
           else if(c == ' ' || c == '\t'){
                pause("Invalid user input!\n\n"
                    "Spaces are not allowed\n"
                    "Any key to retry\n", YES);
				clear();
				i = 0;
				prefix = EMPTY;
			}
			else{
				pause("Invalid user input!\n\n"
                    "Allowed chars are from 0 to 9 and from A to F\n"
                    "Any key to retry\n", YES);
				clear();
				i = 0;
				prefix = EMPTY;
			}
		}
		break;
	}
    hex[i] = '\0';
}


unsigned long long htoi(char hex[])
{
	unsigned int i;
	int exp;
	unsigned long long n;

	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X')) { /* Check if there's the prefix */
        i = 2;
        exp = strlength(hex) - 1 - PREFIX_SIZE;
	}
    else if (  (hex[0] != '0' && (hex[1] == 'x' || hex[1] == 'X'))
            || (hex[0] == 'x' ||  hex[0] == 'X') ) {
        return -1;
    }
	else {
        i = 0;
        exp = strlength(hex)-1;
    }

    n = 0;
	while (hex[i]) {
        if (isdigit(hex[i])) {
			n+=(hex[i] - '0')*pow(16, exp--);
		}
		else if ((hex[i] >= 'A' && hex[i] <= 'F')
             || (hex[i] >= 'a' && hex[i] <= 'f')) {

            n+=(10 + (hex[i] - (isupper(hex[i]) ? 65 : 97)))*pow(16, exp--);
        }
        else if (hex[i] == '.' || hex[i] == ':')
            NULL;

        ++i;
	}
	return n;
}


int strlength(char s[])
{
	unsigned int i;

	i = 0;
    while (s[i] != '\0') {
        if ((s[i] >= 'a' || s[i] >= 'A')
         && (s[i] <= 'f' || s[i] <= 'F')
         || (s[i] >= '0' && s[i] <= '9')) {

            ++i;
        }
        else if (s[i] == '.' || s[i] == ':')
            NULL;
        else
            return -1;
    }
    return i;
}


void banner()
{
    fprintf(stderr, "HEX to DEC converter\n\n"
            "If you see in the output that the decimal value is -1\n"
            "it means you gave a wrong value. e.g.: (x1f)16 = (-1)10\n"
            "'x1f' is not valid, it has to be written like this: '0x1f'.\n"
            "Prefix '0x' can be omitted; You can use both upper case and lower case letters.\n\n");
}


void clear()
{
	#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
		system("clear");
	#endif

	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}


void pause(char *__msg, int __in)
{
    if(__msg != NULL && __in != NULL){
        puts(__msg);
        getch();
        fflush(stdin);
    }
    else if(__msg == NULL && __in == NULL){
        //#error "Use of this function here is useless !"
        ;
    }
    else if(__msg == NULL && __in != NULL){
        getch();
        fflush(stdin);
    }
    else if(__msg != NULL && __in == NULL)
        puts(__msg);
}

