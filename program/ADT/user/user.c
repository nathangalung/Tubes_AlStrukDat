#include <stdio.h>

#include "user.h"

void CreateEmptyUser(User *multi)
{
    multi->Count = NilUser;
}

int LengthUser(User multi)
{
    return (multi.Count);
}

void InsertLastUser(User *multi)
{
    multi->Count++;
}