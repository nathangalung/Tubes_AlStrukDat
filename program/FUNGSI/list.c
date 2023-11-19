#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void ListDefault (StaticList artist, Map album_artist, Map song_album)
{
    printf("Daftar Penyanyi : \n");
    for (IdxType i = 0; i < LengthList(artist); i++)
    {
        printf("\t%d. ", i+1);
        DisplayWord(GetList(artist, i));
        printf("\n");
    }

    printf("\n");
    printf("Ingin melihat album yang ada? (Y/N) : ");
    StartWordMark();
    
    if (CompareStringWord(currentWord, "Y"))
    {
        boolean penyanyivalid = false;

        while (!penyanyivalid) 
        {
            printf("Pilih penyanyi untuk melihat album mereka:\n");
            StartWordMark();
            printf("\n");
            for (int i = 0; i < album_artist.Count; i++)
            {
                if (CompareWord1((album_artist).Elements[i].Value, currentWord))
                {
                    penyanyivalid = true;
                } 
                else 
                {
                    printf("Nama artis tidak ditemukan. Silahkan coba lagi.\n");
                    penyanyivalid = false;
                }
            }
        }

        printf("Daftar Album oleh ");
        DisplayWord(currentWord);
        printf(" :\n");

        for (int i = 0; i < album_artist.Count; i++)
        {
            if (CompareWord1((album_artist).Elements[i].Value, currentWord))
            {
                printf("\t%d. ", i+1);
                DisplayWord((album_artist).Elements[i].Key);
                printf("\n");
            }
        }
        printf("\n");

        printf("Ingin melihat lagu yang ada? (Y/N) : ");
        StartWordMark();
        if (CompareStringWord(currentWord, "Y")) 
        {
            boolean laguvalid = false;
            while (!laguvalid) 
            {
                printf("Pilih album untuk melihat lagu yang ada di album : \n");
                StartWordMark();
                printf("\n");
                for (int i = 0; i < song_album.Count; i++)
                {
                    if (CompareWord1((song_album).Elements[i].Value, currentWord))
                    {
                        laguvalid = true;
                    } 
                    else 
                    {
                        printf("Nama album tidak ditemukan. Silahkan coba lagi.\n");
                        laguvalid = false;
                    }
                }
            }
            printf("Daftar lagu di ");
            DisplayWord(currentWord);
            printf(" :\n");

            for (int i = 0; i < song_album.Count; i++)
            {
                if (CompareWord1((song_album).Elements[i].Value, currentWord))
                {
                    printf("\t%d. ", i+1);
                    DisplayWord((song_album).Elements[i].Key);
                    printf("\n");
                }
            }
        }
    }
}

void ListPlaylist (DynamicList *playlist)
{
    printf("Daftar playlist yang kamu miliki: \n");
    if (!IsListEmptyDynamic(*playlist))
    {
        for (int i = 0; i < LengthListDynamic(*playlist); i++)
        {
            printf("\t%d. ", i+1);
            DisplayWord(GetDynamic(*playlist, i));
            printf("\n");
        }
    } 
    else 
    {
        printf("Kamu tidak memiliki playlist.");
        printf("\n");
    }
}