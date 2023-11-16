/* file play.c */

#include <stdio.h>
#include <stdlib.h>
#include "play.h"

int playSong(Map album_artist, Set album, Map song_album, Word song) {
    /* KAMUS LOKAL */
    int i, j;
    Word penyanyi, album_word, lagu;
    
    /* ALGORITMA */
    printf("Daftar Penyanyi:\n");
    for (i = 0; i < album_artist.Count; i++){
        printf("%d.", (i+1));
        DisplayWord(album_artist.Elements[i].Key);
    }
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartWordMark();

    penyanyi = currentWord;
    printf("Daftar Album oleh %c :\n", penyanyi.TabWord);
    for (i = 0; i < album_artist.Count; i++){
        if (CompareWord1(album_artist.Elements[i].Key, penyanyi)){
            for (j = 0; j < album_artist.Elements[i].Value.Count; j++){
                printf("%d.", (j+1));
                DisplayWord(album_artist.Elements[i].Value.Elements[j]);
            }
        }
    }
    printf("Masukkan Nama Album yang dipilih : ");
    StartWordMark();

    album_word = currentWord;
    printf("Daftar Lagu Album %c  oleh %c :\n", album_word.TabWord, penyanyi.TabWord);
    for (int i = 0; i < song_album.Count; i++){
        if (CompareWord1(song_album.Elements[i].Key, album_word)) {
            for (int j = 0; j < song_album.Elements[i].Value.Count; j++) {
                printf("%d.", (j + 1));
                DisplayWord(song_album.Elements[i].Value);
            }
        }
    }
    printf("Masukkan ID Lagu yang dipilih : ");
    StartWordMark();

    lagu = currentWord;
    printf("Memutar lagu %c oleh %c\n", song.TabWord, penyanyi.TabWord);
    return 0;
}


int playPlaylist(LinierList playlist){
    /* KAMUS LOKAL */
    Word currentWord;
    /* ALGORITMA */
    printf("Masukkan ID Playlist: ");
    StartWordMark();
    printf("Memutar playlist %c", currentWord.TabWord);
    return 0;
}