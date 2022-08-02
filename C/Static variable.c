#include <stdio.h>

// prototipo della funzione
void stampa();

int main()
{
   int i;
   for(i=0; i < 5; i++) 
       stampa();
}

void stampa()
{
   int alfa = 0;
   static int beta = 0;
   printf("(int) alfa = %d | (static int) beta = %d\n", alfa, beta);
   ++alfa;
   ++beta;
} 
