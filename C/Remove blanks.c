#include <stdio.h>

int main()
{
    char s1[100], s2[100];
    int i = 0, j = 0;
    int blank_flag = 0;

    printf("Enter some text\n");
    gets(s1);

    while(s1[i] != '\0') {
        if(!(s1[i] == ' ' && s1[i+1] == ' ')) /* Instead of using an else statement */
            s2[j++] = s1[i]; /* j is needed to go through the second string */

        ++i; /* i is needed to go through the first string */
    }

    s2[j] = '\0';

    printf("Text after removing blanks\n%s\n", s2);

    return 0;
}
