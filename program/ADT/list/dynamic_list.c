/* file dynamic_list.c */

#include <stdio.h>
#include <stdlib.h>

#include "dynamic_list.h"

void CreateEmptyDynamic(DynamicList *list)
{
    list->A = (Word *)malloc(MaxEl * sizeof(Word));
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

boolean IsListEmptyDynamic(DynamicList list)
{
    return (list.Neff == 0);
}

Word GetDynamic(DynamicList list, IdxType i)
{
    return (list.A[i]);
}

boolean IsListFullDynamic(DynamicList list)
{
    return (list.Neff == MaxEl);
}

int LengthListDynamic(DynamicList list)
{
    return (list.Neff);
}

void InsertLastDynamic(DynamicList *list, Word word)
{
    list->A[list->Neff] = word;
    list->Neff++;
}