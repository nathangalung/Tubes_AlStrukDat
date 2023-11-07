#include <stdio.h>

#include "charmachine.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void StartInput()
{
    pita = stdin;
    AdvInput();
}

void StartFile(char *filename)
{
    pita = fopen(filename, "r");
    AdvFile();
}
 
void AdvInput()
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

void AdvFile()
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

char GetCC()
{
    return (currentChar);
}

boolean IsEOP()
{
    return (currentChar == MARK);
}