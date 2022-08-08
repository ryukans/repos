#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

main()
{
	int i;
	int range;
	int swapped, temp;
	int arr[MAXSIZE];

	printf("Digit range: ");
	scanf("%d", &range);
	
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
        system("clear");
    #endif

    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #endif

	for(i = 0; i < range; i++){
		scanf("%d", &arr[i]);
	}

	printf("Original list:\n\n");
		for(i = 0; i < range; i++){
			printf("> %d\n", arr[i]);
	}

	while(TRUE){

		swapped = FALSE;

		for(i = 0; i < range; i++){
			if(arr[i] > arr[i+1]){
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
				swapped = TRUE;
			}
		}//end of for.

		if (swapped == FALSE){
			break;
		}
	
	}//end of while.

	printf("\n\nOrdinated list:\n\n");
	for(i = 0; i < range; i++){
		printf("> %d\n", arr[i]);
	}

}
