#include <stdio.h>
#include <loadfx.h>
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0


int getint(int array[], int s);
void sort(int array[], int s);
int binsearch(int x, int n[], int s);

main()
{
	int n, size, numbers[MAXSIZE];

	printf("Digit the length of the array not grater than %d\n> ", MAXSIZE);
	scanf("%d", &size);

	if(size == 0){
		system("cls");
		printf("Size value not valid.\n\nEnd.");
		return 0;
	}

	putchar('\a');
	system("cls");

	printf("Digit the numbers no more than %d !\n", size);
	getint(numbers, size);
	putchar('\a');
	system("cls");

	load("Sorting, wait please . . .");
	putchar('\a');
	sort(numbers, size);

   	printf("Which number would you find ?\n> ");
	scanf("%d", &n);
	putchar('\a');
	system("cls");

	printf("Number found at the index %d\n\n", binsearch(n, numbers, size));

	printf("End.");

	return 0;
}


int getint(int array[], int s)
{

	int i, n;

	for(i = 0; i < s; i++){
		putchar('>');
		scanf("%d", &n);
		array[i] = n;
	}

}


void sort(int array[], int s)
{

	int i, swapped, temp;

	while(TRUE){
		swapped = FALSE;
		for(i = 0; i < s; i++){
			if(array[i] > array[i+1]){
				temp = array[i];
				array[i] = array[i+1];
				array[i+1] = temp;
				swapped = TRUE;
			}
		}//end of for.

		if (swapped == FALSE){
			break;
		}
	}//end of while.

	for(i = 0; i < s; i++){
		printf("%d\n", array[i]);
	}


}


int binsearch(int x, int n[], int s)
{

	int low, mid, high;
	low = 0;
	high = s-1;

	while(low <= high){
		mid = (low+high) / 2;
		if(x < n[mid]){
			high = mid-1;
		}
		else if(x > n[mid]){
			low = mid+1;
		}
		else{
			return mid;
		}

	}
	return printf("Array is empty !\n");

}
