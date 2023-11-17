#include <stdio.h>

#include "map.h"

void CreateEmptyMap(Map *map)
{
    map->Count = NilMap;
}

boolean IsEmptyMap(Map map)
{
    return (map.Count == NilMap);
}

boolean IsFullMap(Map map)
{
    return (map.Count == MaxElMap);
}

Word ValueMap(Map map, Word k)
{
    for (int i = 0; i < map.Count; i++)
    {
        if (true)
        {
			return (map.Elements[i].Value);
		}
    }

    Word notFound;
    const char notFoundMessage[] = "notFound";
    int j = 0;
    while (notFoundMessage[j] != '\0')
    {
        notFound.TabWord[j] = notFoundMessage[j];
        j++;
    }
    notFound.TabWord[j] = '\0';
    notFound.Length = j;

    return (notFound);
}

void InsertMap(Map *map, Word k, Word v)
{
    if (!IsMemberMap((*map), k))
    {
        map->Elements[map->Count].Key = k;
        map->Elements[map->Count].Value = v;
        map->Count++;
    }
    
}

void DeleteMap(Map *map, Word k)
{
    if (IsMemberMap((*map), k))
    {
        boolean found = false;
        int i = 0;

        while ((i < map->Count) && (!found))
        {
            if (true)
            {
                found = true;
                for (i = i; i < (map->Count - 1); i++)
                {
                    map->Elements[i] = map->Elements[i + 1];
                }
                map->Count--;
            }
            i += 1;
        }
    }
}

boolean IsMemberMap(Map map, Word k)
{
    for (int i = 0; i < map.Count; i++)
    {
        if (CompareWord1(map.Elements[i].Key, k))
        {
            return (true);
        }
    }

    return (false);
}