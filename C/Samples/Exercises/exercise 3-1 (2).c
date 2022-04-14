#include <stdio.h>
#define MAXSIZE 10

int binsearch(
	int number,
	int vector[],
	int size
);


int main()
{
	int v[MAXSIZE] = {4, 20, 78, 12, 34, 5, 9, 44, 99, 101};
	int x = 34;

	printf("Found at: v[%d]\n\n", binsearch(x, v, MAXSIZE));

	system("pause");

	return 0;
}


int binsearch(int x, int v[], int n)
{
	int low, mid, high;

	low = 0;
	high = n - 1;
	mid = (low+high) / 2;
	while(low <= high && x != v[mid]){
        if(x < v[mid])
			high = mid - 1;
        else
			low = mid + 1;

        mid = (low+high) / 2;
    }
	return (x == v[mid]) ? mid : -1;
}


