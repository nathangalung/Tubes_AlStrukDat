#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ADT/machine/wordmachine.h"

int main(void)
{
    StartWordMark();
    Word coba = SplitWordBlank(currentWord);
    DisplayWord(coba);
    printf(" ");
    Word ya = SplitWordBlank(coba);

    DisplayWord(ya);


    printf("\n%d\n", ya.Length);
}