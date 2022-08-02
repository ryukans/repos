/*
	Name: aryio - ARRAY INPUT/OUTPUT v1.0
	Copyright: NONE
	Author: Claudio Pisa
	Date: 14/08/16 00:38
	Description: N/A
*/
#include <stdio.h>

//Output
void intput(int array[], int size)//Complete 100%
{
	int index;

	for(index = 0; index < size; index++){
		printf("%d\n", array[index]);
	}
	putchar('\n');
}

void chput(char array[], int size)//Complete 100%
{
	int index;

	for(index = 0; index < size; index++){
		printf("%c\n", array[index]);
	}
}

void strput(char array[])//Complete 100%
{
	printf("%s\n", array);
}


//Input
void intget(int array[], int size)//Complete 99.9%
{
	int index;
		
	for(index = 0; index < size; index++){
		scanf("%d\n", &array[index]); 
	}
	putchar('\n');
}

void strget_array(char array[])//Complete 100%
{
	gets(array);
}

void randget_array(int array[], int size, int range)//Complete 100%
{
	srand(time(NULL));

	int index;

	for(index = 0; index < size; index++){
		array[index] = (rand() & range);
	}
	putchar('\n');
}
