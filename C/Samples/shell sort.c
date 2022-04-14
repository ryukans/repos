#include <stdio.h>
#define MAXSIZE

void shellsort(
    int vector[],
    int size
);


int main()
{
    int v[MAXSIZE] = {2, 37, 100, 9, 67};
    int i;



    printf("Before: ");
    i = 0;
    while(i < MAXSIZE){
        printf("%d", v[i++]);
    }


/*
    putchar('\n');

    shellsort(v, MAXSIZE);

    printf("After: ");
    for (i = 0; i < MAXSIZE; i++)
        printf(" %d", v[i]);
    putchar('\n');*/

    system("pause");

    return 0;
}


/*shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n/2; gap > 0; gap/=2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}
