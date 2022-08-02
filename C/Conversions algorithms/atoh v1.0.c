#include <stdio.h>
#define MAXSIZE 1024

enum boolean { FALSE, TRUE };
enum case_type { LOWER_CASE, UPPER_CASE };

typedef char byte;

void clear(void);
void pause(
    char *__msg,
    int __in
);
void getline(
    char s[],
    int size
);


int main()
{
    int i, j, hex;
    char hexstr[MAXSIZE], line[MAXSIZE];
    byte case_flag;

    printf("Type string\n> ");
    getline(line, MAXSIZE);
    clear();

    while(1){
        printf("Choose case type for conversion\n\n"
               "1.Convert with uppercase\n"
               "2.Convert with lowercase\n");
        char ch = getchar();

        if(ch == '1'){
            case_flag = LOWER_CASE;
            break;
        }
        else if(ch == '2'){
            case_flag = UPPER_CASE;
            break;
        }
        else
            pause("\nInvalid user input\n"
                  "Any key to continue\n", TRUE);
            clear();
    }

    clear();

    i = j = hex = 0;
    while(line[i] != '\0'){
        while(line[i] >= 1){
            hex = line[i]%16;

            if(hex >= 0 && hex <= 9)
                hexstr[j++] = hex+48;
            else if(hex >= 10 && hex <= 15)
                hexstr[j++] = hex-10+(case_flag == LOWER_CASE ? 97 : 65);

            line[i]/=16;
        }
        ++i;
    }

    hexstr[j] = '\0';

    for(i = 0; i < strlen(hexstr); ++i){
        putchar(hexstr[i]);
    }

    return 0;
}

void getline(char s[], int size)
{
    char c;
    int i;

    for(i = 0; i < size && (c = getchar()) != '\n'; ++i)
        s[i] = c;

    s[i] = '\0';
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
        0;
    }
    else if(__msg == NULL && __in != NULL){
        getch();
        fflush(stdin);
    }
    else if(__msg != NULL && __in == NULL)
        puts(__msg);
}

