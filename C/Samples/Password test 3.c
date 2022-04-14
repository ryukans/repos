#include <stdio.h>
#include <string.h>
#define MAX 8 //Password must be no more long than 8 characters 
#define STANDARD 1
#define FALSE 0
#define TRUE 1 

int check(char password[], int *value);

main()
{
	char password[MAX];
	int value;
    
    printf("**MUST BE AT LEAST LONG 8 CHARACTERS AND ONE UPPERCASE - LOWERCASE - NUMBER - SYMBOL**\n");
	
	for (value = FALSE; value != TRUE;){
		
		printf ("Enter password down below\n\n");
		scanf(" %s",password);

		check(password,	value);

	}
	
	return 0; 
}

int check(char password[], int *value)
{
	int index = 0;
	int upper = 0;
	int lower = 0;
	int digit = 0;
	int chars = 0;
	int symbols = 0;
	
	for (index = 0; index < MAX; ++index){
		
		if (islower(password[index])){
			++lower;
		}
		if (isupper(password[index])){
			++upper;
		}
		if (isdigit(password[index])){
			++digit;
		}	
		if (password[index] == '£' || password[index] == '$' || password[index] == '€' || password[index] == '%' || password[index] == '&' || password[index] == '?'){
			++symbols;
		}
	}

	if (upper && lower && digit && symbols == STANDARD){
		printf ("Good to go\n");
		return *value = TRUE; // Cycle break
	}
	else{
		// 'value' is still FALSE
		printf ("Too weak!\n");
	}

}