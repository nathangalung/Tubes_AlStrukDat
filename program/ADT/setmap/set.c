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

void InsertLastSet(Set *set, Word word)
{
    if (!IsMemberSet((*set), word))
    {
        set->Elements[set->Count] = word;
        set->Count++;
    }
}

boolean IsMemberSet(Set set, Word word)
{
    for (int i = 0; i < set.Count; i++)
    {
        if (CompareWord(set.Elements[i], word))
        {
            return (true);
        }
    }

    return (false);
}