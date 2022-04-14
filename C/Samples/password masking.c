#include <stdio.h>

int main()
{
	char username[14];
	char password[8];
	char ch;
	int i = 0;
	
	printf("Username:\t");
	for(i = 0; i < 14 && (ch = getchar()) != '\n'; i++)
		username[i] = ch;
		
	username[i] = '\0';
	
	printf("Password:\t");
	for(i = 0; i < 8; i++){
		password[i] = getch();
		putchar('*');
	}
		
	password[i] = '\0';
	
	printf("\nUsername: %s\nPassword: %s\n", username, password);
	
	return 0;
}
