/*
	Name: Random password generator v1.0
	Copyright: None
	Author: Claudio Pisa
	Date: 20/09/16 00:09
*/

#include <stdio.h>
#include <stdlib.h>
#define LETTERS 52
#define NUMBERS 10
#define MAXSIZE 14

enum{CHARACTER, NUMBER}; 
enum{ZERO, ONE};
enum boolean{FALSE, TRUE}; 


int main()
{

	char alphabet[LETTERS] = {"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz"};
	char digits[NUMBERS] = {"0123456789"};
	char password[MAXSIZE];
	int rn, i, k, tm, alpha, number;
	/*int j; DEBUG USE ONLY !*/
	
	srand(time(NULL));
	
	printf("How many times do you want to generate a password ?\n>: ");
	scanf("%d", &tm); /*The user establishes how many time the password has to be printed out.*/

	system("cls"); /*The screen is cleared.*/
	
	/*Is checked how many times the user has establisched how many time the password has to be printed out.
	All of this is just for aesthetic reasons.*/
	switch(tm){
		case ZERO: /*In case of the user types zero, the program ends.*/
			printf("End.");
			return EXIT_SUCCESS;
		
		case ONE: /*In case of the user types one, one password will be printed.*/
			printf("Password:\n"); 
			printf("_______________\n\n"); /*Aesthetics bar.*/
			break;
		
		default: /*In case of the user types a number greater than one, a passwords list will be printed.*/
			printf("Passwords list:\n"); 
			printf("_______________\n\n"); /*Aesthetics bar.*/
			break;
	}
		
	for(k = 0; k < tm; k++){
		for(i = 0; i < MAXSIZE; i++){
			rn = (rand() % 2);/*Generate a random number to 0 to 1. */

			if(rn == CHARACTER){
				alpha = (rand() % LETTERS);
				/*printf("alpha value: %d\n\n", alpha); DEBUG USE ONLY ! */
				password[i] = alphabet[alpha];
			}
			else if(rn == NUMBER){
				number = (rand() % NUMBERS);
				/*printf("digit value: %d\n\n", number); DEBUG USE ONLY */
				password[i] = digits[number];
			}
		}
			password[i] = '\0';
			printf(">: %s\n", password);
	}
	
	/*	DEBUG USE ONLY !
	for(j = 0; j < MAXSIZE; j++){
		printf("Index %d) %c\n\n", j, password[j]);
	}*/

	return EXIT_SUCCESS;

}

