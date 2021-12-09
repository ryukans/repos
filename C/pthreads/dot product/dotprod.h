#include <pthread.h>

typedef struct dot_product_data {
    double  *x; //array
    double  *y;
    double  sum;
    int     len;  
} DotProd;

void* dotprod(void* arg);
