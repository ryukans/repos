#include <stdio.h>
#define MAXCHAR 50
#define LINE_FEED '\x0a'
#define TRUE 1
#define FALSE 0


void getline(char line[], int size);
int any(char line1[], char line2[]);

main()
{

	char line1[MAXCHAR];
	char line2[MAXCHAR];
	int i, j, x;
	int *Pany;
	
	printf("Digit the strings no longer than 50 characters !\nPress Enter to continue . . .");
   	getchar();
   	for(i = 0; i < 50; i++){
   		printf("|\n");
	}
   	system("cls");


    printf("Digit first string:\n");
	getline(line1, MAXCHAR);

	printf("Digit second string:\n");
	getline(line2, MAXCHAR);
	
	Pany = any(line1, line2);
	
	for (i = 0; i < 2; i++){
    	printf("%d", Pany[i]);
   	}



}


void getline(char line[], int size)
{
	int i, ch;

	for(i = 0; i < size-1 && (ch = getchar()) != LINE_FEED; i++){
    	line[i] = ch;
	}
	
	line[i] = '\0';

}

int* any(char s1[], char s2[])
{

	int i, j;
	int swapped = FALSE;
	static int loc[MAXCHAR];

	 for (i = 0; s1[i] != '\0'; ++i){    
        for (j = 0; s2[j] != '\0'; ++j){ 
            if (s1[i] == s2[j]){
                loc[i] = i;
                swapped = TRUE;
            }
        }
    }
    

    if (swapped == TRUE){
    	return loc;
    }
    else{
    	return -1;
    }
}
