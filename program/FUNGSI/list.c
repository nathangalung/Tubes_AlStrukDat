#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void ListDefault (StaticList artist, Map album_artist, Map song_album)
{
    printf("Daftar Penyanyi :\n");
    for (int index = 0; index < LengthList(artist); index++)
    {
        printf("\t%d. ", index+1);
        DisplayWord(GetList(artist, index));
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
            printf("Pilih penyanyi untuk melihat album mereka: ");
            StartWordMark();
            printf("\n");
            int i = 0;
            while (!penyanyivalid && (i < LengthList(artist)))
            {
                if (CompareWord1(artist.A[i], currentWord))
                {
                    penyanyivalid = true;
                }
                else 
                {
                    i++;
                }
            }
        }

        if (penyanyivalid)
        {
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
                    printf("Pilih album untuk melihat lagu yang ada di album : ");
                    StartWordMark();
                    printf("\n");
                    int i = 0;
                    while (!laguvalid && (i < album_artist.Count))
                    {
                        if (CompareWord1((album_artist).Elements[i].Key, currentWord))
                        {
                            laguvalid = true;
                        }
                        else
                        {
                            i++;
                        }
                    }
                }

                if (laguvalid)
                {
                    printf("Daftar lagu di ");
                    DisplayWord(currentWord);
                    printf(" :\n");

                    for (int i = 0; i < song_album.Count; i++)
                    {
                        if (CompareWord1(song_album.Elements[i].Value, currentWord))
                        {
                            printf("\t%d. ", i+1);
                            DisplayWord(song_album.Elements[i].Key);
                            printf("\n");
                        }
                    }
                }
                else
                {
                    printf("Nama album tidak ditemukan. Silahkan coba lagi.\n");
                }
            }
        }
        else
        {
            printf("Nama artis tidak ditemukan. Silakan coba lagi.\n");
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