/* file queue.c */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void queueSong(Map album_artist, Set album, Map song_album){
        
    /* KAMUS LOKAL */
    int i, j;
    Word penyanyi, album_word, lagu;
    
    /* ALGORITMA */
    printf("Daftar Penyanyi:\n");
    for (i = 0; i < album_artist.Count; i++){
        printf("\t%d.", (i+1));
        DisplayWord(album_artist.Elements[i].Key);
    }
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartWordMark();
    
    // ADA STATIC LIST ARTIS
    penyanyi = currentWord;
    printf("Daftar Album oleh ");
    DisplayWord(penyanyi);
    printf(": \n");
    for (i = 0; i < album_artist.Count; i++){
        if (CompareWord1(album_artist.Elements[i].Key, penyanyi)){
            for (j = 0; j < album_artist.Count; j++){
                printf("\t%d.", (j+1));
                DisplayWord(album_artist.Elements[i].Value);
            }
        }
    }
    printf("Masukkan Nama Album yang dipilih : ");
    StartWordMark();
    
    album_word = currentWord;
    printf("Daftar Lagu Album ");
    DisplayWord(album_word);
    printf(" oleh ");
    DisplayWord(penyanyi);
    printf(": \n");
    for (i = 0; i < song_album.Count; i++){
        if (CompareWord1(song_album.Elements[i].Key, album_word)) {
            for (j = 0; j < song_album.Count; j++) {
                printf("\t%d.", (j + 1));
                DisplayWord(song_album.Elements[i].Value);
            }
        }
    }
    printf("Masukkan ID Lagu yang dipilih : ");
    StartWordMark();
    
    lagu = currentWord;
    printf("Berhasil menambahkan lagu");
    DisplayWord(lagu); // HARUS CARI JG NAMA LAGUNYA APA
    printf(" oleh ");
    DisplayWord(penyanyi);
    printf(" ke queue\n");
}

void queuePlaylist(LinierList playlist){
    printf("Masukkan ID Playlist: ")
    StartWordMark();
    
    idPlaylist = currentWord;
    printf("Berhasil menambahkan playlist ");
    DisplayWord(idPlaylist); // HARUS CARI NAMA PLAYLIST JG
    printf(" ke queue\n");
}

void queueSwap(Queue *queue, int *a, int *b){
    if (IsMemberQueue(queue, *a) && IsMemberQueue(queue, *b)){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;

        printf("Lagu");
        DisplayWord(queue->T[(*a)-1]); // nama lagu 1
        printf("berhasil ditukar dengan");
        DisplayWord(queue->T[(*b)-1]); // nama lagu 2

    } else {
        int notmember; // harus cari yg not member yg mana
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", notmember);
    }

}

void queueRemove(int *arr){
    if (IsMemberQueue(queue, *arr)){
        int i;
        for (i = *arr; i < queue->Count; i++){
            queue->T[i-1] = queue->T[i];
        }
        queue->Count--;
        printf("Lagu");
        DisplayWord(); // nama lagu
        printf("oleh");
        DisplayWord(); // nama penyanyi
        printf("telah dihapus dari queue");

    } else {
        printf("Lagu dengan urutan ke %d tidak ada.", *arr);
    }
}

void queueClear(Queue *queue){
    CreateEmptyQueue(queue);
}