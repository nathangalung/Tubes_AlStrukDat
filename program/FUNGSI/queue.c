/* file queue.c */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void queueSong(Queue queue, StaticList artist, Map album_artist, Map song_album, User *multi, StaticList *playing, int idx_user){
        
    /* KAMUS LOKAL */
    int i, index, idlagu;
    boolean penyanyivalid, albumvalid, found;
    Word penyanyi, album_word, lagu;

    /* ALGORITMA */
    printf("\nDaftar Penyanyi:\n");
    for (index = 0; index < LengthList(artist); index++) {
        printf("\t%d. ", index + 1);
        DisplayWord(GetList(artist, index));
        printf("\n");
    }

    printf("\nMasukkan Nama Penyanyi yang dipilih : ");
    StartWordMark();
    printf("\n");

    penyanyi = currentWord;
    penyanyivalid = false;

    while (!penyanyivalid) {
        i = 0;
        while (!penyanyivalid && (i < LengthList(artist))) {
            if (CompareWord1(artist.A[i], currentWord)) {
                penyanyivalid = true;
            } else {
                i++;
            }
        }
    }

    if (penyanyivalid) {
        printf("Daftar Album oleh ");
        DisplayWord(currentWord);
        printf(" :\n");

        index = 0;
        for (i = 0; i < album_artist.Count; i++) {
            if (CompareWord1((album_artist).Elements[i].Value, currentWord)) {
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

        while (!albumvalid) {
            i = 0;
            while (!albumvalid && (i < album_artist.Count)) {
                if (CompareWord1((album_artist).Elements[i].Key, currentWord)) {
                    albumvalid = true;
                } else {
                    i++;
                }
            }
        }

        if (albumvalid) {
            printf("Daftar Lagu Album ");
            DisplayWord(album_word);
            printf(" oleh ");
            DisplayWord(penyanyi);
            printf(":\n");

            index = 0;
            for (i = 0; i < song_album.Count; i++) {
                if (CompareWord1(song_album.Elements[i].Value, album_word)) {
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

            if (idlagu <= 0 || idlagu > song_album.Count) {
                printf("Lagu tidak ditemukan.\n");
            } else {
                for (index = 0; index < song_album.Count; index++){
                    if (CompareWord1(song_album.Elements[index].Value, album_word) && (found == false)) {
                        printf("Berhasil menambahkan lagu \"");
                        DisplayWord((song_album).Elements[index + idlagu - 1].Key);
                        printf("\" oleh \"");
                        DisplayWord(penyanyi);
                        printf("\" ke queue.\n");
                        found = true;
                    }
                }
            }
        }
        else {
            printf("Album tidak ditemukan.\n");
        }
    }
    else {
        printf("Penyanyi tidak ditemukan.\n");
    }
}

// void queuePlaylist(LinierList playlist){
//     printf("Masukkan ID Playlist: ")
//     StartWordMark();
    
//     idPlaylist = currentWord; // harus cari nama playlist
//     printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", idPlaylist.TabWord); // HARUS CARI NAMA PLAYLIST JG
// }

// void queueSwap(Queue *queue, int *a, int *b){
//     if (IsMemberQueue(queue, *a) && IsMemberQueue(queue, *b)){
//         int temp;
//         temp = *a;
//         *a = *b;
//         *b = temp;

//         printf("Lagu \"%s\" berhasil ditukar dengan \"%s\".", queue->T[(*a)-1], queue->T[(*b)-1]);

//     } else {
//         int notmember; // harus cari yg not member yg mana
//         printf("Lagu dengan urutan ke \"%d\" tidak terdapat dalam queue!", notmember);
//     }

// }

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

// void queueClear(Queue *queue){
//     CreateEmptyQueue(queue);
// }