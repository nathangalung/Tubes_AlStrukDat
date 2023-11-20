/* file play.c */

#include <stdio.h>
#include <stdlib.h>
#include "play.h"

void playSong(StaticList artist, Map album_artist, Map song_album){

    /* KAMUS LOKAL */
    int i, index, idlagu;
    boolean penyanyivalid, albumvalid;
    Word penyanyi, album_word, lagu;

    /* ALGORITMA */
    printf("\nDaftar Penyanyi:\n");
    for (index = 0; index < LengthList(artist); index++)
    {
        printf("\t%d. ", index + 1);
        DisplayWord(GetList(artist, index));
        printf("\n");
    }

    printf("\nMasukkan Nama Penyanyi yang dipilih : ");
    StartWordMark();
    printf("\n");

    penyanyi = currentWord;
    penyanyivalid = false;

    while (!penyanyivalid)
    {
        i = 0;
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

        index = 0;
        for (i = 0; i < album_artist.Count; i++)
        {
            if (CompareWord1((album_artist).Elements[i].Value, currentWord))
            {
                printf("\t%d. ", index + 1);
                DisplayWord((album_artist).Elements[i].Key);
                printf("\n");
                index++;
            }
        }
        printf("\n");

        printf("Masukkan Nama Album yang dipilih : ");
        StartWordMark();
        printf("\n");

        album_word = currentWord;
        albumvalid = false;

        while (!albumvalid)
        {
            i = 0;
            while (!albumvalid && (i < album_artist.Count))
            {
                if (CompareWord1((album_artist).Elements[i].Key, currentWord))
                {
                    albumvalid = true;
                }
                else
                {
                    i++;
                }
            }
        }

        if (albumvalid)
        {
            printf("Daftar Lagu Album ");
            DisplayWord(album_word);
            printf(" oleh ");
            DisplayWord(penyanyi);
            printf(":\n");

            index = 0;
            for (i = 0; i < song_album.Count; i++)
            {
                if (CompareWord1(song_album.Elements[i].Value, album_word))
                {
                    {
                        printf("\t%d. ", index + 1);
                        DisplayWord(song_album.Elements[i].Key);
                        printf("\n");
                        index++;
                    }
                }
            }

            printf("\nMasukkan ID Lagu yang dipilih : ");
            StartWordMark();
            printf("\n");

            lagu = currentWord;
            idlagu = atoi(currentWord.TabWord);

            if (lagu.TabWord[0] == '\0' || idlagu <= 0 || idlagu > song_album.Count)
            {
                printf("Lagu tidak ditemukan.\n");
            }
            else
            {
                printf("Memutar lagu ");
                DisplayWord((song_album).Elements[idlagu-1].Key); // BELOM BENER T^T
                printf(" oleh ");
                DisplayWord(penyanyi);
                printf(".\n");
            }
        }
        else
        {
            printf("Album tidak ditemukan.\n");
        }
    }
    else
    {
        printf("Penyanyi tidak ditemukan.\n");
    }
}

void playPlaylist(DynamicList *playlist) {
    /* KAMUS LOKAL */
    int idPlaylist;
    boolean idPlaylistValid;
    Word namaplaylist;
    
    /* ALGORITMA */
    printf("Masukkan ID Playlist: ");
    StartWordMark();
    namaplaylist = currentWord;
    idPlaylist = atoi(currentWord.TabWord);

    idPlaylistValid = false;

    if (!idPlaylistValid) {
        if (idPlaylist <= 0 || idPlaylist > LengthListDynamic(*playlist)) {
            printf("Playlist tidak ditemukan.\n");
        } else {
            idPlaylistValid = true;
            printf("Memutar playlist ");
            DisplayWord((*playlist).A[idPlaylist-1]);
            printf(".\n");
        }
    }
}