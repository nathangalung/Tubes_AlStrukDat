#include <stdio.h>

#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        AdvInput();
    }
}

void IgnoreNewlines()
{
    while (currentChar == NEWLINE)
    {
        AdvFile();
    }
}

void StartWordInput()
{
    StartInput();
    IgnoreBlanks();
    if (IsEOP())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordInput();
    }
}

void StartWordFile(char *filename)
{
    StartFile(filename);
    if (currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        AdvWordFile();
    }
}

void AdvWordInput()
{
    IgnoreBlanks();
    if (currentChar == BLANK)
    {
        EndWord = true;
    }
    else
    {
        CopyWordInput();
        IgnoreBlanks();
    }
}

void AdvWordFile()
{
    if (currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        CopyWordFile();
        IgnoreNewlines();
    }
}

void CopyWordInput()
{
    int i = 0;

    while ((!IsEOP()) && (currentChar != BLANK))
    {
        currentWord.TabWord[i] = currentChar;
        AdvInput();
        i++;
    }
    currentWord.Length = i;
}

Word CopyWordFile()
{
    int i = 0;

    while ((!EOP) && currentChar != NEWLINE)
    {
        currentWord.TabWord[i] = currentChar;
        AdvFile();
        i++;
    }
    currentWord.Length = i;

    return (currentWord);
}