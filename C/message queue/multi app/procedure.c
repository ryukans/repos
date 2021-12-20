#include "header.h"
#include <stdlib.h>
#include <time.h>

T genval(int i_sx, int i_dx)
{
    T val = (T)(rand()+i_sx)/(T)(RAND_MAX/i_dx);
    
    return val;
}