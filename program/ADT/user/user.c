#include <stdio.h>

#include "user.h"

void CreateEmptyUser(User *multi)
{
    multi->Count = NilUser;
}

void InsertLastUser(User *multi)
{
    multi->Count++;
}