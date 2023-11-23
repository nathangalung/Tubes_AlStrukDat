#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

unsigned int customRand(unsigned int max)
{
    time_t t;
    srand((unsigned int)time(&t));
    static unsigned int seed = 0;
    seed = (seed << 3) + (unsigned int)time(NULL) + rand() + (unsigned int)pow(seed, 2) + (unsigned int)sqrt(seed);
    return (seed % (max)) + 1;
}

int main()
{
    unsigned int randomNum = customRand(3);
    printf("Nomor acak ke : %u\n",randomNum);
    return 0;
}