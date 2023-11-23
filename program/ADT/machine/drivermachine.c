#include <stdio.h>

#include "wordmachine.h"

int main()
{
    Word satu, dua;
    printf("\nTulis 2 kata : ");
    StartWordMark();

    satu = SplitWordBlank(currentWord);
    dua = SplitWordLeftBlank(currentWord);
    

    printf("Panjang kata total : %d\n", currentWord.Length);
    printf("\nKata pertama : ");
    DisplayWord(satu);
    printf("\nPanjang kata pertama: %d\n", satu.Length);
    printf("\nKata kedua : ");
    DisplayWord(dua);
    printf("\nPanjang kata kedua: %d\n", dua.Length);

    Word filename = {"../../CONFIG/default.txt", 24};
    printf("\nCEK BERDASARKAN FILE : ");
    DisplayWord(filename);
    StartWordNewline(filename);
    printf("\n\nCetak Word :\n");
    DisplayWord(currentWord);
    while (!EOP)
    {
        AdvWordNewline();
        printf("\n");
        DisplayWord(currentWord);
    }
    printf("\n\n");

    return 0;
}