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

void PushStack(Stack *S, Word word)
{
    Top(*S)++;
    InfoTop(*S) = word;
}

void PopStack(Stack *S, Word *word)
{
    (*word) = InfoTop(*S);
    Top(*S);
}