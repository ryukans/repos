#include <stdio.h>

#define MAXSIZE 15

int binsearch(
	int x,
	int vector[],
	int size );



int main()
{
	int v[MAXSIZE] = { 1, 12, 16, 24, 26, 27, 36, 34, 38, 48, 78, 89, 90, 244, 345 };
	int x, pos;

	printf("Number to find\n>: ");
	scanf("%d", &x);
	pos = binsearch(x, v, MAXSIZE);
	printf("foud at: %d\n", pos);

	return 0;
}

/* binsearch: find x in v[0] <= v[1] ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	while (low <= high && x != n[mid]){
		mid = (low + high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	return mid; 
}



