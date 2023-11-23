#include "stack.h"
#include <stdio.h>

void CreateEmptyStack(Stack *S)
{
    Top(*S) = NilStack;
}

boolean IsEmptyStack(Stack S)
{
    return (Top(S) == NilStack);
}

boolean IsFullStack(Stack S)
{
    return (Top(S) == MaxElStack);
}

int LengthStack(Stack S)
{
    int length;
    if (IsEmptyStack(S))
    {
        length = 0;
    }
    else
    {
        length = Top(S) + 1;
    }
}

void Push(Stack *S, Word word)
{
    Top(*S)++;
    InfoTop(*S) = word;
}

void Pop(Stack *S, Word *word)
{
    (*word) = InfoTop(*S);
    Top(*S)--;
}