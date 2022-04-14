/*
	Name: Lower case conversion.
	Copyright: None
	Author: www.cquestions.com 
	Code source: http://www.cquestions.com/2008/01/write-c-program-to-conversion-from_03.html
	Date: 19/09/16 18:33
	Description: ASCII value of 'A' is 65 while 'a' is 97. Difference between them is 97 – 65 = 32
	So if we will add 32 in the ASCII value of 'A' then it will be 'a' and if will we subtract 32 in ASCII value of 'a' it will be 'A'. It is true for all alphabets.
	In general rule:
	Upper case character = Lower case character – 32
	Lower case character = Upper case character + 32
	Note: The code has been edited.	
*/

#include<stdio.h>
#include<string.h>

/*The code has been edited.*/

int main()
{
	
	char str[100];
	int i;
  
	puts("Enter any string >: ");
	gets(str);

	system("cls");
	
	
	printf("The string is >: %s", str);
	
	for(i = 0; i <= strlen(str); i++){
		if(str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
	}

    printf("\nThe string in lower case is >: %s", str);
	
	return 0;
	
}
