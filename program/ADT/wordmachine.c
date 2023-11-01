#include <stdio.h>

#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void STARTWORD()
{
    START();
    ADVWORD();
}

void ADVWORD()
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
{
    int i = 0;

    while ((currentChar != MARK) && (currentChar != BLANK))
    {
        if (i < NMax)
        {
            currentWord.TabWord[i] = currentChar;
            i++;
        }
        ADV();
    }
    currentWord.Length = i;
}