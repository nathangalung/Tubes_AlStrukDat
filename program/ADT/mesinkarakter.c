#include <stdio.h>
#include <string.h>

#include "mesinkarakter.h"

char currentChar;
boolean EOP;

void START()
{
    currentChar = getchar();
    EOP = IsEOP();
}

void ADV()
{
    currentChar = getchar();
    EOP = IsEOP();
}

char GetCC()
{

    return (currentChar);
}

boolean IsEOP()
{
    return (currentChar == MARK);
}