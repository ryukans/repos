#include <ctype.h> /* Per la definizione di toupper */
#include <stdio.h> /* Per la definizione di getchar, putchar ed EOF */
 
main()
{
  int ch;
 
  while((ch = getchar()) != EOF)
    putchar(toupper(ch));
	
	return 0;
}

