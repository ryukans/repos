#include <stdio.h>
#define SIZE 27

main()
{
	char n[SIZE] = "abcde";
	int low, mid, high, x;
	x = 'e';
	low = 0;
	high = SIZE;


	while(low <= high && mid != x){
		mid = (low+high) / 2;
		if(x < n[mid]){
			high = mid-1;
		}
		else{
			low = mid+1;
		}

	}

 	return mid;

}
