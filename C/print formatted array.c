#include <stdio.h>
#define MAXSIZE 25

void randomfill(
	int a[],
	int size
);

int main()
{
	int a[MAXSIZE];
	int i;

	randomfill(a, MAXSIZE);

	for(i = 0; i < MAXSIZE; i++)
		printf("%6d%c", a[i], (i%10 == 9 || i == MAXSIZE-1) ? '\n' : ' ');

    return 0;
}


void randomfill(int a[], int size)
{
	const int HIGH = 20, LOW = 1;
	int i;

	srand(time(NULL));

	for(i = 0; i < size; i++)
		a[i] = rand() % (HIGH+1-LOW) + LOW;
}
