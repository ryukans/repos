

#include <stdio.h>
#define MAXSIZE 7

int main()
{
	char password[MAXSIZE];
	int i, times;

	srand(time(NULL));

	printf("How many times ?\n");
	scanf("%d", &times);

	while(times--){
		i = 0;
		while(i < MAXSIZE){
		    password[i++] = rand() % (126 + 33) - 33;
        }
		printf("%s\n", password);
	}


	return 0;
}
