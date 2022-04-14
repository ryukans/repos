#include <stdio.h>

int main()
{
	int c, boolean;

    boolean = ((c = getchar()) != EOF);
	printf("%d\n", boolean); /* 1 if a character is typed, else 0 */

	return 0;

}
