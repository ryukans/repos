#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1024

enum boolean { FALSE, TRUE };
enum case_type { LOWER_CASE = 'l', UPPER_CASE = 'u' };

void clear(void);
void pause(
    char *__msg,
    int __in
);
void getline(
    int s[],
    int size
);
void atoh(
	int s[],
	char hex[],
	char case_type
);
int stringlen(
    char s[]
);


int main()
{
    char hex[MAXSIZE], case_type;
    int line[MAXSIZE];
    int i, j;

    while(1){
        printf("Choose case type for the conversion\n\n"
               "1.Convert with uppercase\n"
               "2.Convert with lowercase\n");
        char ch = getchar();
        fflush(stdin);

        if(ch == '1'){
            case_type = UPPER_CASE;
            break;
        }
        else if(ch == '2'){
            case_type = LOWER_CASE;
            break;
        }
        else{
            pause("\nInvalid user input\n"
                  "Any key to continue\n", TRUE);
            clear();
        }
    }

    clear();

    printf("String:\n");
    getline(line, MAXSIZE);

    putchar('\n');

    atoh(line, hex, case_type);

    i = j = 0;
    while(hex[i] != '\0'){
        if(j == 2){
            if(i % 50 == 0){
                printf("-\n-");
                j = 0;
            }
            else{
                putchar(' ');
                j = 0;
            }
        }
        else{
            putchar(hex[i++]);
            ++j;
        }
    }

    getch();

    return EXIT_SUCCESS;
}


void getline(int s[], int size)
{
    int c, i;

    for(i = 0; i < size && (c = getchar()) != '\n'; ++i)
        s[i] = c;

    s[i] = '\0';
}


int stringlen(char s[])
{
    int i;

    i = 0;
	while(s[i] != '\0')
		i++;

    return i;
}


void atoh(int s[], char hex[], char case_type)
{
	int i, j, alpha, tmp;

	i = j = alpha = tmp = 0;
    while(s[i] != '\0'){
        alpha = s[i++];
        while(alpha >= 1){
            tmp = alpha % 16;
            if(tmp >= 0 && tmp <= 9){
                hex[j++] = tmp + '0';
            }
            else if(tmp >= 10 && tmp <= 15){
                hex[j++] = tmp - 10 + ((case_type == UPPER_CASE) ? 'A' : 'a');
            }

            alpha/=16;
        }
    }
    hex[j] = '\0';

    i = tmp = 0; /* -i- and -tmp- are now used for this swap-cycle */
    while(i < stringlen(hex)){
        tmp = hex[i];
        hex[i] = hex[i+1];
        hex[i+1] = tmp;
        i+=2; /* A character, in hexadecimal, always consists of two digits/letter */
    }
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
    //TODO: Complete the second -else if- block
    if(__msg != 0 && __in != 0){
        puts(__msg);
        getch();
        fflush(stdin);
    }
    else if(!__msg && !__in){
        //#error "Use of this function here is useless !"
        0;
    }
    else if(!__msg && __in != 0){
        getch();
        fflush(stdin);
    }
    else if(__msg != 0 && !__in)
        puts(__msg);
}

