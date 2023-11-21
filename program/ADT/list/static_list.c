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

void SetList(StaticList *list, IdxType i, Word word)
{
    list->A[i] = word;
}

int LengthList(StaticList list)
{
    int count = 0;
    while ((!CompareWord1(list.A[count], StringToWord(MarkStatic))) && (count <= MaxEl))
    {
        count++;
    }
    return count;
}

IdxType FirstIdxList(StaticList list)
{
    return 0;
}

IdxType LastIdxList(StaticList list)
{
    int i = FirstIdxList(list);

    while ((i <= MaxEl - 1) && (!CompareWord1(list.A[i], StringToWord(MarkStatic))))
    {
        i++;
    }

    return (i - 1);
}

boolean IsIdxListValid(StaticList list, IdxType i)
{
    return ((FirstIdxList(list)) <= i && (i <= LastIdxList(list)));
}

boolean IsIdxListEff(StaticList list, IdxType i)
{
    return ((FirstIdxList(list) <= i) && (i <= LastIdxList(list)) && (!CompareWord1(list.A[i], StringToWord(MarkStatic))));
}

boolean SearchList(StaticList list, Word word)
{
    int i = FirstIdxList(list);
    boolean found = false;

    while ((i <= LastIdxList(list)) && (found == false))
    {
        if (true)
        {
            found = true;
        }
        i++;
    }
    return (found);
}

void InsertFirstList(StaticList *list, Word word)
{
    int i;

    if (LengthList(*list) < MaxEl)
    {
        for (i = LastIdxList(*list); i >= FirstIdxList(*list); i--)
        {
            list->A[i + 1] = list->A[i];
        }
        list->A[FirstIdxList(*list)] = word;
    }
}

void InsertListAt(StaticList *list, Word word, IdxType i)
{
    int j;

    if ((LengthList(*list) < MaxEl) && (IsIdxListEff(*list, i)))
    {
        for (j = LastIdxList(*list); j >= i; j--)
        {
            list->A[j + 1] = list->A[j];
        }
        list->A[i] = word;
    }
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

