#include <time.h>
#include <stdio.h>
#include <stdlib.h>
/*include <utility.h>*/

#define LENGHT 14
#define MAXCHARS 30
#define clrscr() \
	system("cls");
/*#define RANDOM(X, Y, Z) \
	(X) = rand() % (Y +1) (Z)
*/

enum boolean{ FALSE, TRUE };

int random(int, int, int);
int exclude(char[], char, int);
void menu(char[]);

int main()
{
	srand(time(NULL));

	int i, excluded;
	char state0, temp, ch, password[LENGHT], blacklist[MAXCHARS];

	printf("Do you want to exclude one or more characters ? Y/N\n");

	state0 = getchar();

	if(state0 == 'Y'){
		excluded = TRUE;
		menu(blacklist);
		printf("Type characters to exclude - no more than %d\n", MAXCHARS);
		
		for(i = 0; i < MAXCHARS && (ch = getchar()) != '\n'; i++)
			blacklist[i] = ch;

		blacklist[i] = '\0';


	}
	else if(state0 == 'N')
		excluded = FALSE;

	/* Generating the password */
	for(i = MAXCHARS; i > 0; i--){
		temp = random(temp, 93, 33);
		if(!excluded)
			password[i] = temp;
		else
			if(!exclude(blacklist, temp))  /*TRUE = is excluded - FALSE = is not excluded*/
				password[i] = temp;
			else
				NULL;
	}

	clrscr();

	printf("%s", password);

	return EXIT_SUCCESS;
}

int random(int x, int y, int z)
{
	return x = rand() % (y + 1) + z;
}

int exclude(char line[], char c)
{
	int i;

	for(i = 0; line[i] != '\0'; i++){
		if(c == line[i])
			return TRUE; /* The character is excluded */
		else
			return FALSE; /* The character is not excluded */
	}

}

void menu(char line[])
{
/*temp == line[i] ? printf("%c -EXCLUDED-\n", temp,) : printf("%c", temp)*/
	int i, j, k;

	printf("Actual characters set:\n");

	for(i = 0, j = 33, k = 125; j <= k; i++, j++){
		if(j == line[i]) /* if(j >= line[FIRST INDEX] || j <= line[LAST INDEX]) */
			printf("%c -EXCLUDED-\n", j);
		else
			printf("%c\n", j);
	}

}

