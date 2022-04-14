#include <stdio.h>
#define MAXSIZE 1024
#define EMPTY -1
#define FULL 0

enum boolean { NO, YES };

void clear(void);
void pause(
	char *__msg,
	int __in
);
void gethex(
	char hex[]
);
void htoa(
    char hex[],
    char str[]
);


int main()
{
    char hex[MAXSIZE], str[MAXSIZE];
    gethex(hex);


    return 0;
}


void gethex(char hex[])
{
	unsigned int i;
	int prefix = EMPTY;
	char c;

    while(1){
    	i = 0;
        while(i < MAXSIZE && (c = getchar()) != '\n'){
           if(prefix == EMPTY)
                if(c == '0' && ((c = getchar()) == 'x' || c == 'X')){
                    if(prefix == FULL){ /* unreachble */
                        pause("Invalid user input!\n\n"
                            "Too many prefixes or invalid prefix position\n"
                            "Any key to retry\n", YES);
                        clear();
                        i = 0;
                        prefix = EMPTY;
                    }
                    else{
                        hex[i++] = '0';
                        hex[i++] = c;
                        prefix = FULL;
                        c = getchar(); /* Get the next char in the input buffer */
                    }
                }
            if(isdigit(c)
				|| ((c >= 'A' || c >= 'a') && (c <= 'F' || c <= 'f'))){

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


void htoa(char s1[], char s2[])
{
	unsigned int i, j;

	if(s1[0] == '0' && (s1[1] == 'x' || s1[1] == 'X')){ /* Check if there's the prefix */
        i = 2;
	}
    else if(s1[0] != '0' && (s1[1] == 'x' || s1[1] == 'X')){
        printf("error\n");
    }
    else if(s1[0] == 'x' || s1[0] == 'X'){
        printf("error\n");
    }
	else{
        i = 0;
    }

    j = 0;
   	while(s1[i] != '\0'){
   		if(isdigit(s1[i])){ /* if(s1[i] >= 0 && s1[i] <= 9) */
			s2[j++]+=(s1[i] - '0') * pow(16, exp--);
		}
		else if((s1[i] >= 'A' && s1[i] <= 'F')
             || (s1[i] >= 'a' && s1[i] <= 'f')){

			s2[j++]+=(10 + (s1[i] - (isupper(s1[i]) ? 'A' : 'a')));
			/* dec += hex_alphas[hex[i]-(isupper(hex[i]) ? 65 : 97)]*pow(16, exp--); Old expression used with the array */
        }
        ++i;
   	}
	s2[j] = '\0';
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
