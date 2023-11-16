/* file play.c */

#include <stdio.h>
#include <stdlib.h>
#include "play.h"

void printArtist(Map album_artist){
    printf("Daftar Penyanyi:\n");
    for (int i = 0; i < album_artist.Count; i++){
        printf("%d.", (i+1));
        DisplayWord(album_artist.Elements[i].Key);
    }
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartWordMark();
}

void printAlbumArtist(Map album_artist, Word penyanyi){
    printf("Daftar Album oleh %c :\n", penyanyi.TabWord);
    for (int i = 0; i < album_artist.Count; i++){
        if (CompareWord1(album_artist.Elements[i].Key, penyanyi)){
                for (int j = 0; j < album_artist.Elements[i].Value.Count; j++){
                    printf("%d.", (j+1));
                    DisplayWord(album_artist.Elements[i].Value);
                }
        }
    }
    printf("Masukkan Nama Album yang dipilih : ");
    StartWordMark();
}

void printAlbumSong (Map album, Map song_album, Word album_word, Word penyanyi){
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
}

int playSong(Map album_artist, Set album, Map song_album, Word song, Word penyanyi) {
    /* KAMUS LOKAL */
    /* ALGORITMA */
    printArtist(album_artist);
    printAlbumArtist(album_artist, penyanyi);
    printAlbumSong(album, song_album, album, penyanyi);
    printf("Memutar lagu %c oleh %c\n", song.TabWord, penyanyi.TabWord);
    return 0;
}


int playPlaylist(LinkedList playlist){
    /* KAMUS LOKAL */
    Word currentWord;
    /* ALGORITMA */
    printf("Masukkan ID Playlist: ");
    StartWordMark();
    printf("Memutar playlist %c", currentWord.TabWord);
    return 0;
}