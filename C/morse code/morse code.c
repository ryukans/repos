#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define COLUMN_SIZE 26
#define ROW_SIZE 26
#define MAXSIZE 150

enum { DOT = 0x2e, LINE = 0x2d, BSLASH = 0x5c, NEW_LINE = 0x0a, SPACE = 0x20 } char_set;

void getline(
	char s[]
);
int str_length(
	char s[]
);
void convert_case(
	char s[]
);
void play_sound(
	char morse[]
);


int main()
{
	unsigned int i, k, column, row;
	char message[MAXSIZE], morse[MAXSIZE];
	char chart[ROW_SIZE][COLUMN_SIZE] =
	{
		{ DOT, LINE },
		{ LINE, DOT, DOT, DOT },
		{ LINE, DOT, LINE, DOT },
		{ LINE, DOT, DOT },
		{ DOT },
		{ DOT, DOT, LINE, DOT },
		{ LINE, LINE, DOT },
		{ DOT, DOT, DOT, DOT },
		{ DOT, DOT },
		{ DOT, LINE, LINE, LINE },
		{ LINE, DOT, LINE },
		{ DOT, LINE, DOT, DOT },
		{ LINE, LINE },
		{ LINE, DOT },
		{ LINE, LINE, LINE },
		{ DOT, LINE, LINE, DOT },
		{ LINE, LINE, DOT, LINE },
		{ DOT, LINE, DOT },
		{ DOT, DOT, DOT },
		{ LINE },
		{ DOT, DOT, LINE },
		{ DOT, DOT, DOT, LINE },
		{ DOT, LINE, LINE },
		{ LINE, DOT, DOT, LINE },
		{ LINE, DOT, LINE, LINE },
		{ LINE, LINE, DOT, DOT }
	};

	printf("Type string\n> ");
	getline(message);

	printf("Morse code:\n");

	k = 0;
	for(i = 0, row = message[i]-97; i < str_length(message); row = message[++i]-97){ /* Inserting letter by letter */
		for(column = 0; chart[row][column] != '\0'; column++, k++)
            if(chart[row][column] == SPACE)
                morse[k] == BSLASH;
            else
                morse[k] = chart[row][column]; /* Inserting dots and lines */

        morse[k++] = SPACE; /* After a letter put a space */
	}

    morse[--k] = '\0';

    printf("%s\nPlay sound ? Y/N\n", morse);
    char ch = getchar();
    if(ch == 'Y' || ch == 'y')
        play_sound(morse);

    getch();

    return 0;
}


void getline(char s[])
{
	char ch;
	int i = 0;
	while(i < MAXSIZE && (ch = getchar()) != NEW_LINE)
		s[i++] = ch;

    s[i] = '\0';

    convert_case(s);
}


int str_length(char s[])
{
	int i = 0;
	while(s[i] != '\0')
		++i;

	return i;
}


void convert_case(char s[])
{
	int i = 0;
	while(s[i] != '\0'){
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		++i;
	}
}


void play_sound(char morse[])
{
	int i = 0;
    while(morse[i] != '\0'){
        if(morse[i] == DOT)
            Beep(550, 100);
        else if(morse[i] == LINE)
            Beep(550, 200);
        else if(morse[i] == SPACE)
            Sleep(150);
        ++i;
    }
}

