#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define LENGHT 14
#define MAXCHARS 30

enum boolean{FALSE, TRUE};

void getline(char line[]);
int exclude(char line[], char c, int state);
void menu(char line[]);

int main()
{
	
	char blacklist[MAXCHARS];
	char password[LENGHT];
	char c;
	int state;
	
	srand(time(NULL));
	
	printf("Do you want to exclude one or more characters ? Y/N\n");
	c = getchar();
	c = toupper(c);
	if(c == 'Y'){
		
		getline(blacklist);
		
	}
	else if(c == 'N')
		state = FALSE;
	else{
		printf("Syntax error !");
		return EXIT_FAILURE;
	}
	
	printf("%d\n %s", state, blacklist);
}

void getline(char line[])
{
	
	int i;
	char ch;
	
	printf("Inserisci\n");
	i = 0;
	while(i < MAXCHARS && (ch = getchar()) != '\x0a')
		line[i++] = ch;
		
	line[i] = '\0';
	
}









