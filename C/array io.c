#include <stdio.h>
#include <windows.h>

#define MAXSIZE 255 /* array size */
#define BELL 0x07	/* bell character */

enum ops { WRITE = '1', READ = '2', EXIT = '3' };

void write(char line[], int size);
size_t length(char line[]);
void pase(void);
void clear(void);
void options(void);
void flush(void); //clear stdin

int main()
{
	int option = 0;
	char array[MAXSIZE];

	do {
		options();

		option = getchar();
		flush();

		switch (option) {
			case WRITE: {
				clear();
				printf("Write:\n");
				write(array, MAXSIZE);
				break;
			}
			case READ: {
				clear();
				printf("Array content: \"%s\"\t\tTotal chars: %d\n\n", array, (int)length(array));
				pause();
				break;
			}
			case EXIT: {
			    clear();
			    printf("End.\n");
			    pause();
				exit(0);
			}
			case '\n': {
			    printf("\tChoose and option first.\n");
			    pause();
			    break;
			}
			default: {
				putchar(BELL);
				printf("\n\tError, invalid input form user\n");
				pause();
				break;
			}
        } //end of switch

        clear();
	} while (1);

}


void write(char s[], int lim)
{
	int i = 0, ch = 0;

	while (--lim > 0 && (ch = getchar()) != EOF && ch != '\n')
		s[i++] = ch;
	s[i] = '\0';
}


size_t length(char s[])
{
	size_t i = 0;

	while (s[i] != '\0')
		++i;

	return i;
}


void clear()
{
    #if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
		system("clear");
	#endif

	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}

void pause()
{
	printf("Press any key to continue.\n");
    getch();
}

void options()
{
	printf("1.Write into the array\n"
               "2.Print out array content\n"
               "3.Close program\n");
}

void flush()
{
    int c;

    while((c = getchar()) != EOF && c != '\n');
}




