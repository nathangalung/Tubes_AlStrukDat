/* file queue.c */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void queueSong(StaticList artist, Map album_artist, Map song_album, User *multi, StaticList *playing, int idx_user)
{

    /* KAMUS LOKAL */
    int i, index, idlagu;
    boolean penyanyivalid, albumvalid, found;
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
                    printf("\t%d. ", index + 1);
                    DisplayWord(song_album.Elements[i].Key);
                    printf("\n");
                    index++;
                }
            }

            printf("\nMasukkan ID Lagu yang dipilih : ");
            StartWordMark();
            printf("\n");

            found = false;
            lagu = currentWord;
            idlagu = atoi(currentWord.TabWord);

            if (idlagu <= 0 || idlagu > song_album.Count)
            {
                printf("Lagu tidak ditemukan.\n");
            }
            else
            {
                for (index = 0; index < song_album.Count; index++)
                {
                    if (CompareWord1(song_album.Elements[index].Value, album_word) && (found == false))
                    {
                        printf("Berhasil menambahkan lagu \"");
                        DisplayWord((song_album).Elements[index + idlagu - 1].Key);
                        printf("\" oleh \"");
                        DisplayWord(penyanyi);
                        printf("\" ke queue.\n");

                        Enqueue(&multi->Elements[idx_user].Queue, song_album.Elements[index + idlagu - 1].Key);

                        found = true;
                    }
                }
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
    printf("\n");
}

void queuePlaylist(User multi, StaticList *playing, int idx_user, PlaylistSong playlist_song){
    
    /* KAMUS LOKAL */
    int idPlaylist, i;
    address lagu;
    boolean idPlaylistValid;
    Word Playlist;

    /* ALGORITMA */
    printf("\nMasukkan ID Playlist: ");
    StartWordMark();
    Playlist = currentWord;
    idPlaylist = atoi(currentWord.TabWord);

    idPlaylistValid = false;

    if (!idPlaylistValid)
    {
        if (IsListEmptyDynamic(multi.Elements[idx_user].Playlist) || idPlaylist < 0 || idPlaylist > LengthListDynamic(multi.Elements[idx_user].Playlist))
        {
            printf("\nPlaylist tidak ditemukan.\n");
        }
        else
        {
            idPlaylistValid = true;
            printf("\nBerhasil menambahkan playlist \"");
            DisplayWord(GetDynamic(multi.Elements[idx_user].Playlist, idPlaylist-1));
            printf("\" ke queue.\n");

            lagu = First(playlist_song.Playlist[idPlaylist - 1].Song);
            for (i = 0; i < NbElmt(playlist_song.Playlist[idPlaylist - 1].Song); i++)
            {
                Enqueue(&multi.Elements[idx_user].Queue, Info(lagu));
                lagu = Next(lagu);
            }
        }
    }
    printf("\n");
}

void queueSwap(User *multi, Word word, int idx_user)
{
    boolean found_1 = false, found_2 = false;
    int ctr = 0;
    int idx_1 = WordToInt(SplitWordLeft(word)), idx_2 = WordToInt(SplitWordBlank(word));
    Word temp;

    if ((idx_1 >= 1 || idx_1 <= LengthQueue(multi->Elements[idx_user].Queue)) && (idx_2 >= 1 ||idx_2 <= LengthQueue(multi->Elements[idx_user].Queue)))
    {
        temp = multi->Elements[idx_user].Queue.Buffer[idx_1 - 1];
        multi->Elements[idx_user].Queue.Buffer[idx_1 - 1] = multi->Elements[idx_user].Queue.Buffer[idx_2 - 1];
        multi->Elements[idx_user].Queue.Buffer[idx_2 - 1] = temp;

        printf("\nLagu \"");
        DisplayWord(SplitWordMark(SplitWordMark(multi->Elements[idx_user].Queue.Buffer[idx_1 - 1])));
        printf("\" berhasil ditukar dengan \"");
        DisplayWord(SplitWordMark(SplitWordMark(multi->Elements[idx_user].Queue.Buffer[idx_2 - 1])));
        printf("\"\n");
    }
    else if ((idx_1 < 1 || idx_1 > LengthQueue(multi->Elements[idx_user].Queue)) && (idx_2 < 1 || idx_2 > LengthQueue(multi->Elements[idx_user].Queue)))
    {
        printf("\nLagu dengan urutan ke %d dan %d tidak terdapat dalam queue!\n", idx_1, idx_2);
    }
    else if (idx_1 < 1 || idx_1 > LengthQueue(multi->Elements[idx_user].Queue))
    {
        printf("\nLagu dengan urutan ke %d tidak terdapat dalam queue!\n", idx_1);
    }
    else
    {
        printf("\nLagu dengan urutan ke %d tidak terdapat dalam queue!\n", idx_2);
    }

    printf("\n");
}

// void queueRemove(int *arr){
//     if (IsMemberQueue(queue, *arr)){
//         int i;
//         for (i = *arr; i < queue->Count; i++){
//             queue->T[i-1] = queue->T[i];
//         }
        
//         queue->Count--; // harus cari nama lagu dan penyanyinya
//         printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue.", queue->T[(*arr)-1], queue->T[(*arr)-1]);

//     } else {
//         printf("Lagu dengan urutan ke %d tidak ada.", *arr);
//     }
// }

void queueClear(User *multi, int idx_user)
{
    CreateEmptyQueue(&multi->Elements[idx_user].Queue);
    printf("\nQueue berhasil dikosongkan.\n");
    printf("\n");
}