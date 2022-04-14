#include <stdio.h>

void pause();
void clear();

int main()
{
    long long n = 0;
    char ch;

    clear();

    printf("%c%c +  key to increment\n"
           "%c%c -  key to decrement\n"
           "%c%c *  key to multiply it with its own value\n"
           "%c%c /  key to halve its own value\n"
           "%c%cEsc key to exit\n\n",
           0xC3, 0xC4, 0xC3, 0xC4, 0xC3, 0xC4, 0xC3, 0xC4, 0xC3, 0xC4);

    pause();
    clear();

    while(1){
        printf("value>: %d", n);
        ch = getch();
        if(ch == '+'){
            n++;
            clear();
        }
        else if(ch == '-'){
            --n;
            clear();
        }
        else if(ch == '*'){
            n*=n;
            clear();
        }
        else if(ch == '/'){
            n/=2;
            clear();
        }
        else if(ch == 0x1B){
            clear();
            printf("End.");
            return 0;
        }
        else{
            printf("\n\nError, invalid user input.\n");
            pause();
            clear();
        }

    }

}

void pause()
{
	printf("Press any key to continue.\n");
	getch();
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

