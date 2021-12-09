#include <sys/time.h>

long getinstant(void);

long getinstant()
{
    struct timeval t1;
    struct timezone t2;
    long instant;
    
    gettimeofday(&t1, &t2);
    instant = (t1.tv_sec*1000000)+(t1.tv_usec);

    return instant;
}