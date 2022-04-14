/*
   .                     .
	Name: loadfx v1.2
	Copyright: None
	Author: Claudio Pisa
	Date: 26/08/16 20:06
	Description: N/A
   .                     .
						  */

#include <stdio.h>
#define FULL 100

void load(char line[], int tm);
void clear();

load(char line[], int tm)
{
	int p = 0;
	clear();
	while(p < FULL+1){
		printf("%s %d%%", line, p);
		clear();
		p += tm;
	}
	/*
	for(p = 0; p < FULL+1; p+=tm){
		printf("%s . . .  %d%%", line, p);
		system("cls");
	}*/

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

