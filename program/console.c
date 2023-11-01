#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"


boolean cmp_word(Word a, Word b)
{
    boolean found = true;
    int i = 0;

    if (a.Length != b.Length)
    {
        found = false;
    }
    else
    {
        while (((a.TabWord[i] != MARK) || (a.TabWord[i] != BLANK)) && (found = true))
        {
            if (a.TabWord[i] != b.TabWord[i])
            {
                found = false;
            }
        }
    }

    return (found);
}

Word split_word(Word a)
{
    Word temp;
    int length = 0, i = 0;

    while (a.TabWord[i] != BLANK)
    {
        i++;
    }

    int j = i + 1;

    while (a.TabWord[j] != MARK)
    {
        a.TabWord[length] = a.TabWord[j];
        length++, j++;
    }
    a.Length = length;

    return (a);
}