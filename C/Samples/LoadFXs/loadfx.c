/*
    Name: loadfx v1.0
    Copyright: None
    Author: Claudio Pisa
    Date of creation 26/08/16 20:06*
    Date of update: 03/03/17 00:30
    Description: This program is an instance of how it works, the original program is "loadfx.h".

    *Date of creation may not be exact.
*/

/*
    Old documentation:
        Name: Loading status v0.1
        Copyright: None
        Author: Claudio Pisa
        Date: 26/08/16 20:06
        Description: N/A
*/

#include <stdio.h>
#define FULL 100

void clear();

int main()
{
	int perc = 0;
	char line[50] = "Loading . . .";

	while(perc <= FULL){
		printf("%s %d%%", line, perc);
		clear();
		++perc;
	}

	printf("Completed !\nPress Enter to continue.\n");
	getch();
	clear();

	return 0;
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

