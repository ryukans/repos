#include <stdio.h>
#include <stdlib.h>
#define LINE_FEED '\x0a'
#define ALPHABET 36
#define MAXCHAR 4
#define MAXRANGE 2

/*
s1 = ALPHABET
s2 = INDEXES
s0 = S2 (input)
*/

enum boolean{FALSE, TRUE}; 

void find(char s0[], char s1[], int s2[]);
void expand(char s1[], int s2[]);

int main()
{
	
	char s0[MAXCHAR];
	char s1[ALPHABET] = "abcedfghijklmnopqrstuvwxyz0123456798";
	int s2[MAXRANGE];
	int i, j, c;

	printf("Type range:\n");

	for(i = 0; i < MAXCHAR && (c = getchar()) != LINE_FEED; i++){
		if(isalpha(c) || c == '-'){
			s0[i] = (tolower(c));
		}
		else{
			printf("Syntax error !");
			return EXIT_FAILURE;
		}
	}
	s0[i] = '\0';

	find(s0, s1, s2);

	expand(s1, s2);
	
	return 0;

}

void find(char s0[], char s1[], int s2[])
{

	int i, j, k = 0;
	
	for(i = 0; s0[i] != '\0'; i++){
		for(j = 0; s1[j] != '\0'; j++){
			if(s0[i] == s1[j]){
                s2[k++] = j;
			}
		}
	}

}

void expand(char s1[], int s2[])
{

	int i;

	if(s2[0] < s2[1]){
		for(i = s2[0]; i <= s2[1]; i++){
			printf("%c\n", s1[i]);
		}
	}
	else{
		for(i = s2[0]; i >= s2[1]; i--){
			printf("%c\n", s1[i]);
		}
	}
	
}
