/*
   .                                                                 .
	Name: squeeze
	Copyright: NONE
	Author: Claudio Pisa
	Date: 25/08/16 00:53
	Description: Exercise 2-4 p.48
	Write an alternative version if squeeze(s1,s2)* that deletes
	each character in s1 that matches any character in the string s2.
   .	                                                             .

                                                                      */


// *squeeze: delete all c from s

/*
   void squeeze(char s[], int c)
   {
   	int i, j;

   	for (i = j = 0; s[i] != '\0'; i++)
   		if (s[i] != c)
   			s[j++] = s[i];
   	s[j] = '\0';
*/

#include <stdio.h>
#define MAXCHARS 50
#define LINE_FEED '\x0a'

void getline(char line[], int size);
void squeeze(char s1[], char s2[]);

main()
{
	char line1[MAXCHARS];
	char line2[MAXCHARS];
	int i;

	printf("Digit the strings no longer than 50 characters !\nPress Enter to continue.");
   	getchar();
   	system("cls");


    printf("Digit first string:\n");
	getline(line1, MAXCHARS);

	printf("Digit second string:\n");
	getline(line2, MAXCHARS);

	squeeze(line1, line2);

	printf("\nAfter squeezing:\n");
	printf("-------------------\n");
	printf("String: %s", line1);

	return 0;
}


void getline(char line[], int size)
{
	int i, ch;

	for(i = 0; i < size-1 && (ch = getchar()) != LINE_FEED; i++){
    	line[i] = ch;
	}

	line[i] = '\0';

}

void squeeze(char s1[], char s2[])
{

	int i, j, loc;

	for(i = 0; s1[i] != '\0'; i++){
		for(j = 0; s2[j] != '\0'; j++){
			if(s1[i] == s2[j]){
				for(loc = i; s1[loc] != '\0'; loc++){
					s1[loc] = s1[loc+1];
				}
			}
		}
	}

}
