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

boolean StartNewline(Word filename)
{
    boolean found = false;
    pita = fopen(filename.TabWord, "r");
    
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