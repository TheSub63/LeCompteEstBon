#include "numgen.h"

long * genNumbers(int n)
{
    init_genrand(7);
    long * numbers = (long *) malloc (n);
    if(numbers==NULL) exit(1);
    for(int i=0;i<n;i++) {

        numbers[i] = genrand_int32_pos()%100;
    }
    return numbers;
}

long genRes()
{
    return genrand_int32_pos()%900+100;
}