#include <stdio.h>

#include "ADT/list/static_list.h"
#include "ADT/machine/wordmachine.h"

int main()
{
    StaticList artist;

    CreateEmptyStatic(&artist);
    

    Word aku = {"aku", 3};
    Word makan = {"makan", 5};
    Word nasi = {"nasi", 4};

    InsertLastStatic(&artist, aku);
    InsertLastStatic(&artist, makan);
    InsertLastStatic(&artist, nasi);
    for (int i = 0; i < 5; i++)
    {
        DisplayWord(artist.A[i]);
        printf("\n");
    }
}