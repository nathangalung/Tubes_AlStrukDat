#include <stdio.h>

#include "startest.h"



int main(void)
{
    char *filename = "FILE_CONFIG/default.txt";
    start(filename);
    for (int i=0; i<currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");

    AdvWordInput();
    for (int i=0; i<currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");

    AdvWordFile();
    for (int i=0; i<currentWord.Length; i++)
    {
        printf("%c", currentWord.TabWord[i]);
    }
    printf("\n");
}