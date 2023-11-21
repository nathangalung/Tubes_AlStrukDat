/* file static_list.c */

#include <stdio.h>
#include "static_list.h"

void CreateEmptyStatic(StaticList *list)
{
    int i;

    for (i = 0; i < MaxEl; i++)
    {
        (*list).A[i] = StringToWord(MarkStatic);
    }
}

boolean IsListEmpty(StaticList list)
{
    return (LengthList(list) == 0);
}

Word GetList(StaticList list, IdxType i)
{
    return (list.A[i]);
}

int LengthList(StaticList list)
{
    int count = 0;
    while ((!CompareWord(list.A[count], StringToWord(MarkStatic))) && (count <= MaxEl))
    {
        count++;
    }
    return count;
}

void InsertLastStatic(StaticList *list, Word word)
{
    int count = 0;

    while (!CompareStringWord(list->A[count], MarkStatic))
    {
        count++;
    }
    list->A[count] = word;
}

