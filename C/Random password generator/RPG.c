#include <time.h>
#include <stdio.h>
#include <stdlib.h>
/*include <utility.h>*/

#define LENGHT 14
#define MAXCHARS 30

enum boolean{FALSE, TRUE};

int exclude(char[], char, int);
void menu(char[]);

int main()
{

	int i, state, permit;
	char temp, ch, password[LENGHT], blacklist[MAXCHARS];

	srand(time(NULL));

	printf("Do you want to exclude one or more characters ? Y/N\n");
	state = getchar();
	toupper(state);
	
	if(state == 'Y'){
		state = TRUE;
		menu(blacklist);
		
		printf("\n\nType characters to exclude - no more than %d", MAXCHARS);
		
		i = 0;
		while(i < MAXCHARS && (ch = getchar()) != '\x0a')
			blacklist[i++] = ch;
	
		blacklist[i] = '\0';
	}
	else if(state == 'N')
		state = FALSE;
	else
		printf("Syntax error!");


	for(i = MAXCHARS; i > 0; i--){
		temp = (rand() % 93 + 33);
		permit = exclude(blacklist, temp, state); /*TRUE = is excluded - FALSE = is not excluded*/
		if(permit == TRUE)
			0;
		else
			password[i] = temp;
	}

	printf("%s", password);

	return EXIT_SUCCESS;

}

int exclude(char line[], char c, int state)
{

	int i;

	if(state == FALSE)
		return NULL;
	else{
		for(i = 0; line[i] != '\0'; i++){
			if(c == line[i])
				return TRUE;
		}
	}
	
}

void menu(char line[])
{
/*temp == line[i] ? printf("%c -EXCLUDED-\n", temp,) : printf("%c", temp)*/
	int i, j, k;
	char temp;

	printf("Actual characters set:\n");

	for(i = 0, j = 33, k = 126; j <= k; i++, j++){
		temp = j;
		if(temp = line[i]) //if(temp >= line[i] || line[i] <= temp)
			printf("%c -EXCLUDED-\n", temp);
		else
			printf("%c\n", temp);
	}

}