#include <stdio.h>

main()
{
    char c;

	printf("Type character:\n> ");
	c = getchar();
	c = convert_case(c);
	if(is_wovel(c))
        printf("It's a wovel");
    else
        printf("It's not a wovel");

    return 0;

}


int is_wovel(char c)
{
    return(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}


char covert_case(char c)
{
    if(c >= 65 && c <= 90)
        return c+=32;
}
