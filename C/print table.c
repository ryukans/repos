#include <stdio.h>

main()
{
	int rows;
	int columns;
	int i = 0;

	printf("How many rows: ");
	scanf(" %d", &rows);

	printf("How many columns: ");
	scanf(" %d", &columns);

    system("cls");

	for (i = 0; i < rows; i++){
        if(i == 0)
            printf("%c", 0xc9);
		else if(i == rows-1)
			printf("%c \n", 0xbb);
		else
			printf("%c", 0xcd);

	}

    int j = 0;
	for (i = 0; i < columns; i++){
		printf("%c", 0xba);
		for(j = 0; j < rows-2; ++j)
            putchar(' ');
        printf("%c\n", 0xba);
	}

	for (i = 0; i < rows; i++){
        if(i == 0)
            printf("%c", 0xc8);
        else if(i == rows-1)
            printf("%c ", 0xbc);
        else
            printf("%c", 0xcd);

	}





	return 0;

}


















