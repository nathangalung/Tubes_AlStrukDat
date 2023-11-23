/* file dynamic_list.c */

#include <stdio.h>
#include <stdlib.h>

#include "dynamic_list.h"

void CreateEmptyDynamic(DynamicList *list)
{
    list->A = (Word *)malloc(MaxElDynamic * sizeof(Word));
    if (list->A != NULL)
    {
        list->Neff = 0;
    }
}

void DealokasiDynamic(DynamicList *list)
{
    free(list->A);
    list->Neff = 0;
}

boolean IsEmptyDynamic(DynamicList list)
{
    return (list.Neff == 0);
}

boolean IsFullDynamic(DynamicList list)
{
    return (list.Neff == MaxElDynamic);
}

int LengthDynamic(DynamicList list)
{
    return (list.Neff);
}

Word GetDynamic(DynamicList list, IdxType i)
{
    return (list.A[i]);
}

void InsertLastDynamic(DynamicList *list, Word word)
{
    list->A[list->Neff] = word;
    list->Neff++;
}