#include <stdio.h>
#include <string.h>
#define MAX 8 //Password must me no more longer then 8 characters 
#define STANDARD 1

main()
{
	char password[MAX];

	int i = 0;
	int upper = 0;
	int lower = 0;
	int digit = 0;
	int symbols = 0;
	
	
	
	
	printf ("Enter password down below: MAX 8 CHARACTERS\n");
	scanf("%s",password);
	
	i = 0;

	
	
	for (i = 0; i < MAX; ++i){
		if (islower(password[i])){
			++lower;
		}
		if (isupper(password[i])){
			++upper;
		}
		if (isdigit(password[i])){
			++digit;
		}
		if (password[i] == '\n' || '\t'){
			;
		}
		if (password[i] == '£' || password[i] == '$' || password[i] == '€' || password[i] == '%' || password[i] == '&' || password[i] == '?')
			++symbols;
		}
	

	if (upper && lower && digit && symbols == STANDARD){
		printf ("Good to go!");
		printf("%d %d %d %d ", upper,lower,digit,symbols);
	}
	else{
		printf("Too weak!\n **MUST BE AT LEAST ONE: UPPERCASE, LOWERCASE, NUMBER, SYMBOL**\n");
		
	printf("%d %d %d %d ", upper,lower,digit,symbols);
	}

	
	

}
