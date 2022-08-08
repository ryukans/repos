#include <stdio.h>
#define MAXSIZE 150

enum Boolean { False, True };

enum Char_set { 
	NUL	  = 0x00, 
	LF	  = 0x0a, 
	Space = 0x20,
	Line  = 0xc4
};



enum Options {
	OpUpperCase = 0x01,
	OpLowerCase = 0x02,
	OpSpaceChar = 0x04
};

typedef unsigned char flag;



void clear(void);

void pause(
	char *message,
	flag input_flag
);

void drawline(
	unsigned times
);



void generatestring(
	char string[],
	int stringsize
);

int random(
	int maximum_value,
	int minimum_value
);


void settings(void);

int size(void);

unsigned totalstrings(void);




flag options;


void generatestring(char s[], int stringsize)
{ 
	// TODO: recheck for variables
	int i, randchar;
	flag spaceflag, caseflag;

    i = 0;
	while(i < stringsize){ /* Generating the string */
		if(options & OpSpaceChar){
			if(!(spaceflag = (random(5, 0)))) /* If it's zero, put a space */
				s[i++] = Space;
		}
        
		if(options & OpUpperCase)
			s[i++] = random(25, 65);
		else if(options & OpLowerCase)
			s[i++] = random(25, 97);
		else if((options & OpUpperCase) && (options & OpLowerCase)){ //TODO: check operators priority
			if((caseflag = random(3, 0))) /* Non zero is upper case, zero is lower case */
				s[i++] = random(25, 65);
			else{
				s[i++] = random(25, 97);
				break;
			}
		}
	} // while loop end
	
	s[i] = NUL;
}


int random(int max, int min) // TODO: Must enhance this function.
{ return rand() % (max + 1 - min) + min; }


int size()
{
	int stringsize;

    stringsize = 0;
	while(True){
		printf("String size\n>: ");
		scanf(" %d", &stringsize);
		if(stringsize > MAXSIZE || stringsize <= 0){
			pause("Error -- valid size range is from 1 to 150\nRetry\n", True);
			clear();
		}
		else{
            putchar(LF);
			return stringsize;
		}
	}
}


unsigned totalstrings()
{
	unsigned strings;

	strings = 0;
	while(True){
		printf("How many strings ?\n>: ");
		scanf(" %d", &strings);
		if(strings <= 0){
			pause("Error -- valid range is from 1 onwards\nRetry\n", True);
			clear();
		}
		else{
            putchar(LF);
			return strings;
        }
    }
}


void settings()
{
	//TODO: add character generation frequency option 
	unsigned choice;

	printf(
		"Select case type:\n"
		"1.Uppercase only\n"
		"2.Lowercase only\n"
		"3.Both types\n"
		"> "
	);
	choice = 0;
	while(!(choice >= 1 && choice <= 3)){
		scanf(" %d", &choice);
		switch(choice){
			case 1:{
				options = OpUpperCase;
				break;
			}
			case 2:{
				options = OpLowerCase;
				break;
			}
			case 3:{
				options = OpUpperCase | OpLowerCase;
				break;
			}
			default:{
				pause("Error -- options are from 1 to 3\nRetry\n", True);
				clear();
				break;
			}
		}
	}

	putchar(LF);

	printf(
		"Space character:\n"
		"1.On\n"
		"2.Off\n"
		"> "
	);
	choice = 0;
	while(!(choice >= 1 && choice <= 2)){
		scanf(" %d", &choice);
		switch(choice){
			case 1:{
				options |= OpSpaceChar;
				break;
			}
			case 2:{
				NULL;
				break;
			}
			default:{
				pause("Error -- options are from 1 (On) and 2 (Off)\nRetry\n", True);
				clear();
				break;
			}
		}
	}
}

void drawline(unsigned t)
{
	while(t--)
		putchar(Line);
	putchar(LF);
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


void pause(char *msg, flag in)
{
	fflush(stdin);

	if(msg != NULL && in != NULL){
		puts(msg);
		getch();
		fflush(stdin);
	}
	else if(msg == NULL && in == NULL)
		putchar(LF);
	else if(msg == NULL && in != NULL){
		printf("\nPress any key to continue.\n");
		getch();
		fflush(stdin);
	}
	else if(msg != NULL && in == NULL)
		puts(msg);
}
