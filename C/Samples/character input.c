#include <stdio.h>

int main()
{
    const char *question = "Yes or No ?";

    y_or_n_p(question);


    return 0;
}


int y_or_n_p(const char *question)
{
    fputs(question, stdout);

    while (1) {
        int c, answer;

        /* Write a space to separate answer from question. */
        fputc(' ', stdout);

        /* Read the first character of the line.
        This should be the answer character, but might not be. */
        c = tolower(fgetc(stdin));
        printf("%c\n", c);
        answer = c;
        printf("%c\n", answer);

        /* Discard rest of input line. */
        while (c != '\n' && c != EOF)
            c = fgetc(stdin);

        /* Obey the answer if it was valid. */
        if (answer == 'y')
            return 1;
        else if (answer == 'n')
            return 0;
        else 
            fputs("Please answer y or n:", stdout); /* Answer was invalid: ask for valid answer. */
    }
}


/*
int y_or_n_p (const char *question)
{
    printf(question);

    while (1) {
        int c, answer;

        putchar(' ');

        c = tolower(getchar());
        answer = c;


        while (c != '\n' && c != EOF)
            c = getchar();


        if (answer == 'y')
            return 1;
        if (answer == 'n')
            return 0;


        printf("Please answer y or n:");
    }
}
*/
