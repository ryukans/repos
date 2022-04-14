#include <stdio.h> // printf
#include <string.h> // memset
#include <windows.h> // used for sleep function

int main()
{

	char progress[101];
	int i;
	
	for(i = 1; i < 101; i++){
 		memset(progress, '#', i); // put # i/2 times in progress...
		// i've divided i by 2 because the line becomes otherwise too long
 		progress[i+1] = '\0';
 		printf("%s %i%%\n", progress, i); 
 		//system("cls");
 		
 		Sleep(10);
	}
	
	return 0;
}

