#include <stdio.h>

void clear();
void pause();
int random(
    int,
    int
);

int main()
{
    srand(time(NULL));

    int range, rand_int;

	while(1){
        while(1){
            printf("Type range:\t");
            scanf("%d", &range);
            if(range >= 0 && range <= 9){
                break;
            }
            else{
                printf("Error, invalid user input\n");
                pause();
                getchar();
                clear();
            }
        }
        rand_int = random(rand_int, range);
        printf(">: %d\n", rand_int);
        while(1){
            char ch;
            printf("Space to continue\nEsc to exit\n");
            ch = getch();
            if(ch == 0x20){
                clear();
                break;
            }
            else if(ch == 0x1B)
                return 0;
            else{
                printf("Error, ivalid user input.\n");
                pause();
                clear();
            }
        }
    }
}


int random(int var, int range)
{ return var = rand() % (range + 1); }


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
