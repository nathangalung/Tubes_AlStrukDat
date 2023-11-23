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
            if (CompareWord(artist.A[i], currentWord))
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
                if (CompareWord((album_artist).Elements[i].Value, currentWord))
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
                boolean albumvalid = false;
                printf("\nPilih album untuk melihat lagu yang ada di album : ");
                StartWordMark();
                int i = 0;
                while (!albumvalid && (i < album_artist.Count))
                {
                    if (CompareWord(album_artist.Elements[i].Key, currentWord))
                    {
                        albumvalid = true;
                    }
                    else
                    {
                        i++;
                    }
                }

                if (albumvalid)
                {
                    printf("\nDaftar lagu di ");
                    DisplayWord(currentWord);
                    printf(" :\n");
                    int index = 0;
                    for (int i = 0; i < song_album.Count; i++)
                    {
                        if (CompareWord(song_album.Elements[i].Value, currentWord))
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
                    printf("\nNama album tidak ditemukan. Silakan coba lagi!\n");
                }
            }
            else if (!CompareStringWord(currentWord, "N"))
            {
                printf("\nTidak terdapat pilihan tersebut. Silakan coba lagi!\n");
            }
        }
        else
        {
            printf("Nama artis tidak ditemukan. Silakan coba lagi!\n");
        }
    }
    else if (!CompareStringWord(currentWord, "N"))
    {
        printf("\nTidak terdapat pilihan tersebut. Silakan coba lagi!\n");
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
        printf("\n");

        printf("Ingin melihat lagu yang ada? (Y/N) : ");
        StartWordMark();
        if (CompareStringWord(currentWord, "Y"))
        {
            printf("\nMasukkan ID Playlist yang dipilih : ");
            StartWordMark();
            int ID_Playlist = WordToInt(currentWord);

            if (ID_Playlist > 0 && ID_Playlist <= LengthListDynamic(multi.Elements[idx_user].Playlist))
            {
                if (NbElmt(multi.Elements[idx_user].PlaylistSong[ID_Playlist-1].Song) > 0)
                {
                    Word Dash = StringToWord(" - ");
                    address currentSong = First((multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song);
                    int index = 0;
                    for (int i = 0; i < NbElmt(multi.Elements[idx_user].PlaylistSong[ID_Playlist-1].Song); i++)
                    {
                        Word InfoSong = Info(currentSong);
                        Word NamaArtis = SplitWordLeftMark(InfoSong);
                        Word Pilihan = ConcatWord(NamaArtis, Dash);
                        Word NamaAlbum = SplitWordLeftMark(SplitWordMark(InfoSong));
                        Pilihan = ConcatWord(Pilihan, NamaAlbum);
                        Pilihan = ConcatWord(Pilihan, Dash);
                        Word NamaLagu = SplitWordMark(SplitWordMark(InfoSong));
                        Pilihan = ConcatWord(Pilihan, NamaLagu);
                        printf("\t%d. ", index+1);
                        DisplayWord(Pilihan);
                        index++;
                        printf("\n");
                        currentSong = Next(currentSong);
                    }
                }
                else
                {
                    printf("Tidak ada lagu di playlist ini.\n");
                }
            }
            else
            {
                printf("Playlist tidak ada dalam daftar. Silakan coba lagi!\n");
            }
        }
        else if (!CompareStringWord(currentWord, "N"))
        {
            printf("\nTidak terdapat pilihan tersebut. Silakan coba lagi!\n");
        }
    } 
    else 
    {
        printf("\nKamu tidak memiliki playlist.");
        printf("\n");
    }
}