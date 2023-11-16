#include <stdio.h>
#include "list.h"

void ListDefault (StaticList *artist, Map *album_artist, Map *song_album){
    printf("Daftar Penyanyi : \n");
    for (int i = 0; i < LengthList(*artist); i++){
        printf("\t%d. ", i+1);
        DisplayWord(GetList(*artist, i));
    }
    printf("\n");
    printf("Ingin melihat album yang ada? (Y/N) : ");
    StartWordMark();
    if (currentWord.TabWord == "Y"){
        printf("Pilih penyanyi untuk melihat album mereka:\n");
        StartWordMark();
        
    }
}