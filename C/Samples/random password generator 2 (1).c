#include <time.h>
#include <stdio.h>
#include <stdlib.h>
/*include <utility.h>*/

#define LENGHT 14
#define MAXCHARS 30
#define clrscr() \
	system("cls");
#define random(X, Y, Z) \
	(X) = rand() % (Y +1) (Z)

enum boolean{ FALSE, TRUE };

int exclude(char[], char, int);
void menu(char[]);

int main()
{
	srand(time(NULL));

	int i, state1, permit;
	char state0, temp, ch, password[LENGHT], blacklist[MAXCHARS];
	
	printf("Do you want to exclude one or more characters ? Y/N\n");

	state0 = getchar();
	
	if(state0 == 'Y'){
		state1 = TRUE;
		//menu(blacklist);
		clrscr();
		printf("Type characters to exclude - no more than %d\n", MAXCHARS);
		
		i = 0;
		while(i < MAXCHARS && (ch = getchar()) != EOF)
			blacklist[i++] = ch;

		blacklist[i] = '\0';


	}
	else if(state0 == 'N')
		state1 = FALSE;
	
	/* Generating the password */
	for(i = MAXCHARS; i > 0; i--){
		RANDOM(temp, 93, 33);
		if(!exclude(blacklist, temp, state1))  /*TRUE = is excluded - FALSE = is not excluded*/
			password[i] = temp;
		else
			NULL;
	}

	clrscr();

	printf("%s", password);

	return EXIT_SUCCESS;
}

int exclude(char line[], char c, int state)
{

	int i;

	if(!state)
		return FALSE; /* There are not excluded characters */
	else{
		for(i = 0; line[i] != '\0'; i++){
			if(c == line[i])
				return TRUE; /* The character is excluded */
			else
				return FALSE; /* The character is not excluded */ 
		}
	}

}

void menu(char line[])
{
/*temp == line[i] ? printf("%c -EXCLUDED-\n", temp,) : printf("%c", temp)*/
	int i, j, k;
	char temp;

	printf("Actual characters set:\n");

	for(i = 0, j = 33, k = 125; j <= k; i++, j++){
		if(j == line[i]) /* if(j >= line[FIRST INDEX] || j <= line[LAST INDEX]) */
			printf("%c -EXCLUDED-\n", j);
		else
			printf("%c\n", temp);
	}

}
