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

void InsertLastMap(Map *map, Word k, Word v)
{
    if (!IsMemberMap((*map), k))
    {
        map->Elements[map->Count].Key = k;
        map->Elements[map->Count].Value = v;
        map->Count++;
    }
}

boolean IsMemberMap(Map map, Word k)
{
    for (int i = 0; i < map.Count; i++)
    {
        if (CompareWord(map.Elements[i].Key, k))
        {
            return (true);
        }
    }

    return (false);
}