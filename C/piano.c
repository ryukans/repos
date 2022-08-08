#include <stdio.h>
#include <windows.h>

char convert_case(char c);

int main()
{
    int freq[7] = {440, 495, 528, 594, 660, 704, 783};
    int i;

    for(i = 7; i > 0; --i)
        Beep(freq[i], 450);


	return 0;
}


char convert_case(char c)
{
	if(c >= 65 && c <= 90)
		return (c += 32);
	else
		return c;
}
