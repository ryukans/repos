#include <stdio.h>
#define MAXSIZE 27

int main()
{
	char n[MAXSIZE] = "abcdefghijklmnopqrstuvwxyz";
	char x = 'e';
	int mid;
	int	high = MAXSIZE-1;
	int low = 0;
	
	
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
		
	return 0;

}
