#include <ctype.h> 
#include <stdio.h>
#define MAX 50

void capitalize(char array1[], char array2[]);

main ()
{
	char name[MAX];
	char surname[MAX];
	
	printf("Digit your name:\n");
	scanf("%s", &name);
	
	printf("Digit your surname:\n");
	scanf("%s", &surname);
	
	capitalize(name, surname);
	
	
}

void capitalize(char name[], char surname[])
{
	char x;
	char y;
	
	if (islower(name[0]) || islower(surname[0])){   //toupper DOES NOT CHANGES THE VARIABLE VALUE
		
		x = toupper(name[0]);
		name[0] = x;
		
		y = toupper(surname[0]);
		surname[0] = y;
	}
	
	printf("%s %s",name, surname);
}
