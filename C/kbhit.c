#include <stdio.h>
#include <conio.h>

int main()
{
   while(!_kbhit())
      _cputs("Hit me!! ");


   printf("\nKey struck was '%c'\n", _getch());

   return 0;
}
