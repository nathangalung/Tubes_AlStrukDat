/* file static_list.c */

#include <stdio.h>
#include "static_list.h"

void CreateEmptyStatic(StaticList *list){
    int i;

    for (i = 0; i < MaxElStatic; i++)
    {
        (*list).A[i] = StringToWord(MarkStatic);
    }
}

boolean IsEmptyStatic(StaticList list){
    return (LengthStatic(list) == 0);
}

boolean IsFullStatic(StaticList list){
    return (LengthStatic(list) == MaxElStatic);
}

int LengthStatic(StaticList list){
    int count = 0;
    while ((!CompareWord(list.A[count], StringToWord(MarkStatic))) && (count <= MaxElStatic))
    {
        count++;
    }
    return count;
}

Word GetStatic(StaticList list, IdxType i){
    return (list.A[i]);
}

void InsertLastStatic(StaticList *list, Word word){
    int count = 0;

    while (!CompareStringWord(list->A[count], MarkStatic))
    {
        count++;
    }
    list->A[count] = word;
}

