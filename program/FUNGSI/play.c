/* file play.c */

#include <stdio.h>
#include <stdlib.h>
#include "play.h"

void playSong(StaticList artist, Map album_artist, Map song_album, User *multi, StaticList *playing, int idx_user) {    

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
                        printf("Memutar lagu \"");
                        DisplayWord((song_album).Elements[index + idlagu - 1].Key);
                        printf("\" oleh \"");
                        DisplayWord(penyanyi);
                        printf("\".\n");
                        
                        playing->A[idx_user] = song_album.Elements[index + idlagu - 1].Key;
                        CreateEmptyQueue(&multi->Elements[idx_user].Queue);
                        CreateEmptyStack(&multi->Elements[idx_user].History);

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

void playPlaylist(User multi, StaticList *playing, int idx_user, PlaylistSong playlist_song) { // BELOM BERES
    /* KAMUS LOKAL */
    int idPlaylist, i;
    boolean idPlaylistValid;
    address lagu;
    Word namaplaylist;
    
    /* ALGORITMA */
    printf("\nMasukkan ID Playlist: ");
    StartWordMark();
    namaplaylist = currentWord;
    idPlaylist = atoi(currentWord.TabWord);

    idPlaylistValid = false;

    if (!idPlaylistValid) {
        if (IsListEmptyDynamic(multi.Elements[idx_user].Playlist) || idPlaylist < 0 || idPlaylist > LengthListDynamic(multi.Elements[idx_user].Playlist)) {
            printf("\nPlaylist tidak ditemukan.\n");
        } else {
            idPlaylistValid = true;
            printf("\nMemutar playlist \"");
            DisplayWord(GetDynamic(multi.Elements[idx_user].Playlist, idPlaylist-1));
            printf("\".\n");

            lagu = First(playlist_song.Playlist[idPlaylist - 1].Song);
            playing->A[idx_user] = Info(lagu);
            for (i = 1; i < NbElmt(playlist_song.Playlist[idPlaylist - 1].Song); i++) {
                lagu = Next(lagu);
                Enqueue(&multi.Elements[idx_user].Queue, Info(lagu));
                PushStack(&multi.Elements[idx_user].History, Info(lagu));
            }
        }
    }
}