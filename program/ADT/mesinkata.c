#include <stdio.h>

#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void IgnoreNewline()
{
    while (currentChar == NEWLINE && currentChar != MARK)
    {
        ADV();
    }
}

void STARTWORD()
{
    START();
    ADVWORD();
}

void STARTWORDINPUT()
{
    START();
    ADVWORDINPUT();
    IgnoreNewline();
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

void ADVWORDINPUT()
{
    IgnoreBlanks();
    IgnoreNewline();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        IgnoreNewline();
        CopyWordInput();
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
void CopyWordInput()
{
    int i = 0;

    while (currentChar != MARK && currentChar != NEWLINE)
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