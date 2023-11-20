#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ADT/machine/wordmachine.h"

int main(void)
{
    Word ya = {"-3 -1", 5};
    DisplayWord(SplitWordLeft(ya));
    printf("\n");
    int cek = atoi(SplitWordBlank(ya).TabWord);

    printf("%d\n", cek);
}