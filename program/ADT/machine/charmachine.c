#include <stdio.h>
#include <stdlib.h>

#include "charmachine.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void StartMark()
{
    pita = stdin;
    AdvMark();
}

void StartBlank()
{
    pita = stdin;
    AdvBlank();
}

void WordToString(Word word, char *string)
{
    string[word.Length] = '\0';

    for (int i = 0; i < word.Length; i++)
    {
        string[i] = word.TabWord[i];
    }
}

boolean StartNewline(Word filename)
{
    boolean found = false;
    char namafile[50];
    WordToString(filename,namafile);
    pita = fopen(namafile, "r");
    
    if (pita == NULL)
    {
        EOP = true;
        fclose(pita);
    }
    else
    {
        found = true;
        AdvNewline();
    }

    return found;
}
 
void AdvMark()
{
    if (pita == NULL)
    {
        EOP = true;
    }
    else
    {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = feof(pita);

        if (EOP)
        {
            fclose(pita);
        }
    }
}

void AdvBlank()
{
    if (pita == NULL)
    {
        EOP = true;
    }
    else
    {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = feof(pita);

        if (EOP)
        {
            fclose(pita);
        }
    }
}

void AdvNewline()
{
    if (pita == NULL)
    {
        EOP = true;
    }
    else
    {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = feof(pita);

        if (EOP)
        {
            fclose(pita);
        }
    }
}


boolean IsEOPMark()
{
    if (EOP)
    {
        return (EOP);
    }
    else
    {
        return (currentChar == MARK);
    }
}

boolean IsEOPBlank()
{
    if (EOP)
    {
        return (EOP);
    }
    else
    {
        return (currentChar == BLANK);
    }
}

boolean IsEOPNewline()
{
    if (EOP)
    {
        return (EOP);
    }
    else
    {
        return (currentChar == NEWLINE);
    }
}

boolean CompareWord(Word word_1, Word word_2)
{
    if (word_1.Length != word_2.Length)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < word_2.Length; i++)
        {
            if (word_1.TabWord[i] != word_2.TabWord[i])
            {
                return false;
            }
        }
    }

    return true;
}