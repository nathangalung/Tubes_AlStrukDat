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

        printf("\nPilih penyanyi untuk melihat album mereka : ");
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

        if (penyanyivalid)
        {
            printf("Daftar Album oleh ");
            DisplayWord(currentWord);
            printf(" :\n");

            int index = 0;
            for (int i = 0; i < album_artist.Count; i++)
            {
                if (CompareWord1((album_artist).Elements[i].Value, currentWord))
                {
                    printf("\t%d. ", index+1);
                    DisplayWord((album_artist).Elements[i].Key);
                    index++;
                    printf("\n");
                }
            }
            printf("\n");

            printf("Ingin melihat lagu yang ada? (Y/N) : ");
            StartWordMark();
            if (CompareStringWord(currentWord, "Y")) 
            {
                boolean laguvalid = false;
                printf("\nPilih album untuk melihat lagu yang ada di album : ");
                StartWordMark();
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

                if (laguvalid)
                {
                    printf("Daftar lagu di ");
                    DisplayWord(currentWord);
                    printf(" :\n");
                    int index = 0;
                    for (int i = 0; i < song_album.Count; i++)
                    {
                        if (CompareWord1(song_album.Elements[i].Value, currentWord))
                        {
                            printf("\t%d. ", index+1);
                            DisplayWord(song_album.Elements[i].Key);
                            index++;
                            printf("\n");
                        }
                    }
                }
                else
                {
                    printf("\nNama album tidak ditemukan. Silahkan coba lagi!\n");
                }
            }
        }
        else
        {
            printf("Nama artis tidak ditemukan. Silakan coba lagi!\n");
        }
    }
}

void ListPlaylist (User multi, int idx_user)
{
    printf("Daftar playlist yang kamu miliki : \n");
    if (!IsListEmptyDynamic(multi.Elements[idx_user].Playlist))
    {
        int index = 0;
        for (int i = 0; i < LengthListDynamic(multi.Elements[idx_user].Playlist); i++)
        {
            printf("\t%d. ", index+1);
            DisplayWord(GetDynamic((multi.Elements[idx_user].Playlist), i));
            index++;
            printf("\n");
        }
    } 
    else 
    {
        printf("\nKamu tidak memiliki playlist.");
        printf("\n");
    }
}