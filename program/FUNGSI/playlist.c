#include <stdio.h>
#include "playlist.h"

void CreatePlaylist (DynamicList *playlist)
{
    boolean valid = false;
    while (!valid) 
    {
        printf("Masukkan nama playlist yang ingin dibuat : ");
        int countChar, countWS;
        countChar = 0;
        countWS = 0;
        StartWordMark();
        for (int i = 0; i < currentWord.Length; i++) 
        {
            printf("%c", currentWord.TabWord[i]);
            if (currentWord.TabWord[i] != BLANK) 
            {
                countChar++;
            } 
            else 
            {
                countWS++;
            }
        }

        if ((countChar >= 3)) 
        {
            InsertLastDynamic(playlist, currentWord);
            printf("Playlist ");
            DisplayWord(currentWord);
            printf(" berhasil dibuat!\n");
            printf("Silakan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
            valid = true;
        } 
        else 
        {
            printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
            valid = false;
        }
    }
}

void AddSongPlaylist (StaticList *artist, Map *album_artist, Map *song_album, DynamicList *playlist)
{
    printf("Daftar Penyanyi : \n");
    printf("%d", LengthList(*artist));
    for (int i = 0; i < LengthList(*artist); i++)
    {
        printf("\t%d. ", i+1);
        DisplayWord(GetList(*artist, i));
    }
    printf("\n");

    
}
