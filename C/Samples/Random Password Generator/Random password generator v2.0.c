/*
	Name: Random password generator v2.0
	Copyright: None
	Author: Claudio Pisa
	Date: 19/09/16 22:38 

*/

#include <stdio.h>
#include <stdlib.h>
//#include <loadfx.h>
#define MAXSIZE 81 /*Total character that will be use to create the password*/
#define LIMIT 14
#define BIP '\x07' /*Bell character's hexadecimal value*/

enum{ZERO, ONE
};
enum boolean {FALSE, TRUE
};

int main()
{
 
	char chars[MAXSIZE] = {"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz0123456789£$€&!?§<>^@#|=*+-/:"};
	char password[LIMIT];
	int i, j, tm, plural;
	unsigned long int rn;
	/*The array 'chars' contain both alphabet letters(Aa-Zz), numbers (0-9) and symbols.
	The array 'password', actually, will contain the password.
	The variables 'i' and 'j' act as indexes, they will be used in a 'for loop' cycle. 
	The variable 'rn' stands for 'random number'; it will get a random number, it will also acts as index.
	The variable 'tm' stands for 'time'; it will contain the established time to print out the password or passwords in case of the user want to generate more than one password.*/

	srand(time(NULL)); //srand((unsigned int) time(0));
	
	printf("How many times do you want to generate a password ?\n>: ");
	scanf("%d", &tm); /*The user establishes how many time the password has to be printed out.*/
	putchar(BIP); /*Is emitted a sound.*/
	//system("cls"); /*The screen is cleared.*/ NOT NEEDED NOW !
	
//	plural == FALSE ? load("Generating password . . .", 4) : load("Generating passwords . . .", 4);

	/*Is checked how many times the user has establisched how many time the password has to be printed out.
	All of this is just for aesthetic reasons.*/
	switch(tm){
		case ZERO: /*In case of the user types zero, the program ends.*/
			printf("End.");
			return EXIT_SUCCESS;
		
		case ONE: /*In case of the user types one, one password will be printed.*/
			plural = FALSE;
			printf("Password:\n"); 
			printf("_______________\n\n"); /*Aesthetics bar.*/
			break;
		
		default: /*In case of the user types a number greater than one, a passwords list will be printed.*/
			plural = TRUE;
			printf("Passwords list:\n"); 
			printf("_______________\n\n"); /*Aesthetics bar.*/
			break;
	}
	
	
	for(j = 0; j < tm; j++){ /*As many time as established before...*/ 
		for(i = 0; i < LIMIT; i++){ /*...take a random character for eight times (LIMIT) end puts it in 'password'.*/
			rn = (rand() % MAXSIZE); /*'rn' will be equal to the remainder of the division between a random number and 66 (MAXSIZE).*/
			password[i] = chars[rn]; /*The array 'password' gets a character from 'chars'; 'rn' acts as index now.*/
		}
		
		password[i] = '\0'; /*Puts the 'null character' at the end of the array*/
		
		!plural ? printf("\n>:\t%s\n", password) : printf("%d>:\t%s\n\n", j+1,password); /*Prints out the password or the passwords.*/
		
	}
	
	printf("\nEnd.");
	return EXIT_SUCCESS; /*End of the program.*/

}
