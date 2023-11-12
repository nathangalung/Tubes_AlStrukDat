#include <stdio.h>

#include "wordmachine.h"

boolean EndWord;
Word currentWord;

void IgnoreMarks()
{
    while (currentChar == MARK)
    {
        AdvMark();
    }
}

void IgnoreBlanks()
{
    while (currentChar == BLANK)
    {
        AdvBlank();
    }
}

void IgnoreNewlines()
{
    while (currentChar == NEWLINE)
    {
        AdvNewline();
    }
}

void StartWordMark()
{
    StartMark();
    IgnoreMarks();
    if (IsEOPMark())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordMark();
    }
}

void StartWordBlank()
{
    StartBlank();
    IgnoreBlanks();
    if (IsEOPBlank())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordBlank();
    }
}

void StartWordNewline(Word filename)
{
    StartNewline(filename);
    IgnoreNewlines();
    if (IsEOPNewline())
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordNewline();
    }
}

void AdvWordMark()
{
    IgnoreMarks();
    IgnoreBlanks();
    IgnoreNewlines();
    if (IsEOPMark())
    {
        EndWord = true;
    }
    else
    {
        CopyWordMark();
        IgnoreMarks();
    }
}

void AdvWordBlank()
{
    IgnoreMarks();
    IgnoreBlanks();
    IgnoreNewlines();
    if (IsEOPBlank())
    {
        EndWord = true;
    }
    else
    {
        CopyWordBlank();
        IgnoreBlanks();
    }
}

void AdvWordNewline()
{
    IgnoreMarks();
    IgnoreBlanks();
    IgnoreNewlines();
    if (IsEOPNewline())
    {
        EndWord = true;
    }
    else
    {
        CopyWordNewline();
        IgnoreNewlines();
    }
}

void CopyWordMark()
{
    int i = 0;

    while (!IsEOPMark())
    {
        currentWord.TabWord[i] = currentChar;
        AdvMark();
        i++;
    }
    currentWord.Length = i;
}

void CopyWordBlank()
{
    int i = 0;

    while (!IsEOPBlank())
    {
        currentWord.TabWord[i] = currentChar;
        AdvBlank();
        i++;
    }
    currentWord.Length = i;
}

void CopyWordNewline()
{
    int i = 0;

    while (!IsEOPNewline())
    {
        currentWord.TabWord[i] = currentChar;
        AdvNewline();
        i++;
    }
    currentWord.Length = i;
}