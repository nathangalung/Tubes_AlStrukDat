#include <stdio.h>

#include "set.h"


void CreateEmptySet(Set *set)
{
    set->Count = NilSet;
}

boolean IsEmptySet(Set set)
{
    return (set.Count == NilSet);
}

boolean IsFullSet(Set set)
{
    return (set.Count == MaxElSet);
}

void InsertSet(Set *set, Word word)
{
    if (!IsMemberSet((*set), word))
    {
        set->Elements[set->Count] = word;
        set->Count++;
    }
}

void DeleteSet(Set *set, Word word)
{
    int i = 0;
    boolean found = false;

    while ((i < set->Count) && (!found))
    {
        if (CompareWord1(set->Elements[i], word))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    if (found) 
    {
        for (int j = i; j < (set->Count - 1); j++)
        {
            set->Elements[j] = set->Elements[j + 1];
        }

        set->Count--;
    }
}

boolean IsMemberSet(Set set, Word word)
{
    for (int i = 0; i < set.Count; i++)
    {
        if (CompareWord1(set.Elements[i], word))
        {
            return (true);
        }
    }

    return (false);
}