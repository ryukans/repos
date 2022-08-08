#include <stdio.h>
#define MAXSIZE 4


void copy(char arr1[], char arr2[]);

main()
{
	char arr1[MAXSIZE] = {'a','b','c','d'};
	char arr2[MAXSIZE];
	int c;
	int i;


	printf("First array:\n\n");
	for(i = 0; i < MAXSIZE; i++){
		printf("Index %d> %c\n", i, arr1[i]);
	}

	printf("\n\nSecond array:\n\n");
	for(i = 0; i < MAXSIZE; i++){
		printf("Index %d> %c\n", i, arr2[i]);
	}



	printf("\n\nInput:\n");
	c = getchar();
	c = toupper(c);
	putchar(c);

	system("cls");

	if(c == 'Y'){

		copy(arr1,arr2);

		printf("First array:\n\n");
		for(i = 0; i < MAXSIZE; i++){
			printf("Index %d> %c\n", i, arr1[i]);
		}

		printf("\n\nSecond array:\n\n");
		for(i = 0; i < MAXSIZE; i++){
			printf("Index %d> %c\n", i, arr2[i]);
		}

		return 0;
	}

	else if(c == 'N'){
		printf("End program");
		return 0;
	}

	else{
		printf("Error !\nYou digited something else\n\n");
	}

}

void copy(char arr1[], char arr2[])
{
	int i;

	for(i = 0; i < MAXSIZE; i++){
		arr2[i] = arr1[i];
	}
}
