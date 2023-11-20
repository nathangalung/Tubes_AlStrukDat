#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int randint(int n)
{
    if ((n - 1) == RAND_MAX)
    {
        return rand();
    }
    else
    {
        int end = RAND_MAX / n;
        
        end *= n;
        int r;
        while ((r = rand()) >= end);

        return r % n;
    }
}

int main()
{
    int rand_1 = randint(4);
    time_t t;
    srand((unsigned int)time(&t));
    printf("%d\n", ((rand() % (3 - 1 + 1)) + 1));
    printf("%d\n", rand_1);
}