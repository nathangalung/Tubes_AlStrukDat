#include <stdio.h>
#include "ADT/machine/wordmachine.h"

int main()
{
    StartWordMark();
    Word name = {"FILE_CONFIG/", 12};
    Word filename = ConcatWord(name, currentWord);
    printf("%d", filename.Length);
    DisplayWord(filename);
    printf("\n");

    StartWordNewline(filename);

    if (StartWordNewline(filename))
    {
        printf("%c", currentWord.TabWord[0]);
    }
    else
    {
        printf("gagal");
    }
}