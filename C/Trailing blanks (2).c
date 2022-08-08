#include <stdio.h>

enum char_set { SPACE = 0x20, TAB = 0x09 };

int main()
{
	char line[] = "Hello     ";
	int i, j;

	printf("Before:\nLength> %d\n", strlen(line));

	for(i = strlen(line)-1; i > 0; --i)
		if(line[i] != SPACE || line[i] == TAB){
            line[++i] = '\0';
            break;
		}

    /* Alternative ways:

    for(i = strlen(line)-1; i > 0; --i)
		if((line[i] == SPACE  || line[i] == TAB) && line[i-1] != SPACE || line[i-1] != TAB){
            line[i] = '\0';
            break;
		}

    for(i = strlen(line)-1; i > 0; --i)
		if(line[i] == SPACE && line[i-1] != SPACE || line[i] == TAB && line[i-1] != TAB){
            line[i] = '\0';
            break;
		}

    */

	printf("\nAfter:\nLength> %d\nLine> %s\n", strlen(line), line);

	return 0;
}

















