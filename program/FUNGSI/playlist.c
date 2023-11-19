#include <stdio.h>
#include "playlist.h"

void CreatePlaylist (DynamicList *playlist)
{
    boolean valid = false;
    while (!valid) 
    {
        printf("Masukkan nama playlist yang ingin dibuat : ");
        int countChar, countWS;
        countChar = 0;
        countWS = 0;
        StartWordMark();
        for (int i = 0; i < currentWord.Length; i++) 
        {
            printf("%c", currentWord.TabWord[i]);
            if (currentWord.TabWord[i] != BLANK) 
            {
                countChar++;
            } 
            else 
            {
                countWS++;
            }
        }

        if ((countChar >= 3)) 
        {
            InsertLastDynamic(playlist, currentWord);
            printf("Playlist ");
            DisplayWord(currentWord);
            printf(" berhasil dibuat!\n");
            printf("Silakan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
            valid = true;
        } 
        else 
        {
            printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n");
            valid = false;
        }
    }
}

void AddSongPlaylist (StaticList *artist, Map *album_artist, Map *song_album, DynamicList *playlist, LinierList *playlist_song)
{
    printf("Daftar Penyanyi : \n");
    printf("%d", LengthList(*artist));
    for (int i = 0; i < LengthList(*artist); i++)
    {
        printf("\t%d. ", i+1);
        DisplayWord(GetList(*artist, i));
    }
    printf("\n");

    printf("Masukkan Nama Penyanyi yang dipilih :\n");
    StartWordMark();
    Word NamaPenyanyi = currentWord;
    printf("\n");
    for (int i = 0; i < album_artist->Count; i++)
    {
        if (!CompareWord1((*album_artist).Elements[i].Value, currentWord))
        {
            printf("Penyanyi ");
            DisplayWord(currentWord);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        } 
        else 
        {
            printf("Daftar Album oleh ");
            DisplayWord(currentWord);
            printf(" :\n");
            if (CompareWord1((*album_artist).Elements[i].Value, currentWord))
            {
                printf("\t%d. ", i+1);
                DisplayWord((*album_artist).Elements[i].Key);
            }
            printf("\n");
        }
    }

    printf("Masukkan Judul Album yang dipilih :\n");
    StartWordMark();
    Word NamaAlbum = currentWord;
    printf("\n");
    for (int i = 0; i < song_album->Count; i++)
    {
        if (!CompareWord1((*song_album).Elements[i].Value, currentWord))
        {
            printf("Album ");
            DisplayWord(currentWord);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        } 
        else
        {
            printf("Daftar Lagu Album ");
            DisplayWord(currentWord);
            printf(" oleh ");
            DisplayWord(NamaPenyanyi);
            printf(" :\n");
            if (CompareWord1((*song_album).Elements[i].Value, currentWord))
            {
                printf("\t%d. ", i+1);
                DisplayWord((*song_album).Elements[i].Key);
            }
            printf("\n");
        }
    }

    printf("Masukkan ID Lagu yang dipilih :\n");
    StartWordMark();
    int ID_Lagu = WordToInt(currentWord);
    Word LaguPilihan = (*song_album).Elements[ID_Lagu-1].Key;
    printf("\n");

    printf("Daftar Playlist Pengguna : \n");
    if (!IsListEmptyDynamic(*playlist))
    {
        for (int i = 0; i < LengthListDynamic(*playlist); i++)
        {
            printf("\t%d. ", i+1);
            DisplayWord(GetDynamic(*playlist, i));
        }

    }
    printf("\n");

    printf("Masukkan ID Playlist yang dipilih :\n");
    StartWordMark();
    int ID_Playlist = WordToInt(currentWord);
    Word PlaylistPilihan = GetDynamic(*playlist, ID_Playlist-1);
    printf("\n");

    // TINGGAL NGELANJUT INSERTING LAGU KE PLAYLIST_SONG

}

void AddAlbumPlaylist (StaticList *artist, Map *album_artist, Map *song_album, DynamicList *playlist, LinierList *playlist_song)
{
    printf("Daftar Penyanyi : \n");
    printf("%d", LengthList(*artist));
    for (int i = 0; i < LengthList(*artist); i++)
    {
        printf("\t%d. ", i+1);
        DisplayWord(GetList(*artist, i));
    }
    printf("\n");

    printf("Masukkan Nama Penyanyi yang dipilih :\n");
    StartWordMark();
    Word NamaPenyanyi = currentWord;
    printf("\n");
    for (int i = 0; i < album_artist->Count; i++)
    {
        if (!CompareWord1((*album_artist).Elements[i].Value, currentWord))
        {
            printf("Penyanyi ");
            DisplayWord(currentWord);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        } 
        else 
        {
            printf("Daftar Album oleh ");
            DisplayWord(currentWord);
            printf(" :\n");
            if (CompareWord1((*album_artist).Elements[i].Value, currentWord))
            {
                printf("\t%d. ", i+1);
                DisplayWord((*album_artist).Elements[i].Key);
            }
            printf("\n");
        }
    }

    printf("Masukkan Judul Album yang dipilih :\n");
    StartWordMark();
    Word NamaAlbum = currentWord;
    printf("\n");

    printf("Daftar Playlist Pengguna : \n");
    if (!IsListEmptyDynamic(*playlist))
    {
        for (int i = 0; i < LengthListDynamic(*playlist); i++)
        {
            printf("\t%d. ", i+1);
            DisplayWord(GetDynamic(*playlist, i));
        }

    }
    printf("\n");

    printf("Masukkan ID Playlist yang dipilih :\n");
    StartWordMark();
    int ID_Playlist = WordToInt(currentWord);
    Word PlaylistPilihan = GetDynamic(*playlist, ID_Playlist-1);
    printf("\n");     
}