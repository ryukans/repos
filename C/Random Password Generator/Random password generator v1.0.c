#include <stdio.h>
#define LETTERS 52
#define NUMBERS 10
#define MAXSIZE 8 /* Password length */

enum{CHARACTER, NUMBER}; /* CHARACTER = 0 - NUMBER = 1. */

int main()
{	
	srand(time(NULL));
	
	char alphabet[LETTERS] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz",
		 digits[NUMBERS] = "0123456789", 
		 password[MAXSIZE];
	int r, i, j, alpha_index, number_index;
	
	for(i = 0; i < MAXSIZE; i++){
		r = (rand() % 2);
		if(r == CHARACTER){ //if(!(r = (rand() % 2)))
			alpha_index = (rand() % LETTERS);
			//printf("alpha value: %d\n\n", alpha);
			password[i] = alphabet[alpha_index];
		}
		else if(r == NUMBER){
			number_index = (rand() % NUMBERS);
			//printf("digit value: %d\n\n", number);
			password[i] = digits[number_index];
		}
	}
	
	password[i] = '\0';
	
	printf("Password: %s", password);

	/*	
	for(j = 0; j < MAXSIZE; j++){
		printf("Index %d) %c\n\n", j, password[j]);
	}*/

	return 0;

}

