/*
	Name: Password generator v1.0
	Copyright: None
	Author: Claudio Pisa
	Date: 20/09/16 00:05
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXCHAR 20
//Random number generetor function.

int main()
{
	int prefix, i, j, times;
	int long y;
	char const1[MAXCHAR];
	char const2[MAXCHAR];
	char c;

	srand(time(NULL)); //To genere random numbers every time.
	
	printf("Type the costants NO LONGER THAN 20 CHARACTERS\n");
	printf("Press Enter to continue . . .\n");
	getchar();
	
	system("cls");

	printf("Type first costant\n>:");
	gets(const1);

	printf("Type second costant\n>:");
	gets(const2);
	
	printf("Type birth year\n>:");
	scanf("%d", &prefix);
	
	system("cls");

	printf("Now type how many times you want to generate a password\n>:");
	scanf("%d", &times);
	
	system("cls");
	
	if(times > 1 && times > 0){
		printf("Pick one of these:\n");
		printf("------------------\n\n");
	}
		
	for (i = 0, j = 1; i < times; ++i, ++j){
		y = (rand() % 999); //Random number within a range.
		printf ("%d> %s%d%s%d\n\n", j, const1, y+=prefix, const2, prefix);
	}
	
	
	return EXIT_SUCCESS;
}

