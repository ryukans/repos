#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 8 //Password must be no longer than 8 characters.
#define STANDARD_SET 1
enum boolean { FALSE, TRUE
};

main()
{
	char password[MAX];
	int value = FALSE; 
	int i; /* counter */
	int upper, lower, digit, symbols;
	
	upper = lower = digit = symbols = 0; 
	
	printf ("Enter password down below\n\n**MUST BE AT LEAST LONG 8 CHARACTERS AND ONE UPPERCASE - LOWERCASE - NUMBER - SYMBOL**\n\n");
	
//	for ( ; value != TRUE; ){ USELESS ! BETTER WITH A WHILE-LOOP.
	while(value != TRUE){
		scanf("%s",password);
	
		for (i = 0; i < MAX; ++i){

			if (islower(password[i])){
				++lower;
			}
			else if (isupper(password[i])){
				++upper;
			}
			else if (isdigit(password[i])){
				++digit;
			}	
			else if (password[i] == '£' || password[i] == '$' || password[i] == '€' || password[i] == '%' || password[i] == '&' || password[i] == '?'){
				++symbols;
			}
		}
	
	if (upper && lower && digit && symbols == STANDARD_SET){
			value = TRUE;
			printf("Good to go");
			return EXIT_SUCCESS;
		}
		else{
			// 'value' is still FALSE
			printf("Too weak!\n\n");
		}
	}
	
}
