/*
  .                                            .
	Name: aryio - ARRAY INPUT OUTPUT v1.2_beta
	Copyright: NONE
	Author: Claudio Pisa
	Date: 14/08/16 23:06
	Description: N/A
  .                                            .
                                                */

#include <stdio.h>

//Output
/*
void intput(int array[])
{
	int index, ln;

	ln = intlen(array);

	for(index = 0; index < ln; index++){
		printf("%d\n", array[index]);
	}
	putchar('\n');
}
*/

void charput(char array[])
{
	int index, ln;

	ln = strglen(array);

	for(index = 0; index < ln; index++){
		printf("%c\n", array[index]);
	}
}

void strput(char array[])
{
	printf("%s\n", array);
}

void reverse(char array[])
{
	int index, ln;

	ln = strglen(array);

	for(index = ln-1; index >= 0; index--){
		printf("%c", array[index]);
	}
}



//Input
void intget(int array[], int size)
{
	int index;

	for(index = 0; index < size; index++){
		scanf("%d", &array[index]);
	}
	putchar('\n');
}



void strget(char array[], int size)
{
	int index, c;

	for(index = 0; index < size && (c = getchar()) != '\x0a'; index++){
    	array[index] = c;
	}
	putchar('\n');
}



void randget(int array[], int size, int range)
{
	srand(time(NULL));

	int index;

	for(index = 0; index < size; index++){
		array[index] = (rand() % range);
	}
	putchar('\n');
}
