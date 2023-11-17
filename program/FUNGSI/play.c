/* file play.c */

#include <stdio.h>
#include <stdlib.h>
#include "play.h"

int playSong(Map album_artist, Set album, Map song_album){
    
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
    printf("Daftar Album oleh \"%s\" penyanyi: \n");
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
    printf("Daftar Lagu Album \"%s\" oleh \"%s\" : \n", album_word.TabWord, penyanyi.TabWord);
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
    printf("Memutar lagu \"%s\" oleh \"%s\".\n", lagu.TabWord, penyanyi.TabWord);
    return 0;

    // clear queue
}


int playPlaylist(LinierList playlist){ // MASIH BELOM GABUNG KE PLAYLISTNYA
    /* KAMUS LOKAL */
    Word idPlaylist;
    /* ALGORITMA */
    printf("Masukkan ID Playlist: ");
    StartWordMark();
    idPlaylist = currentWord;
    printf("Memutar playlist %c", currentWord.TabWord);
    return 0;
}