#include <stdio.h>
#include "playlist.h"

void CreatePlaylist (User *multi, int idx_user)
{
    printf("\n");
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
            InsertLastDynamic(&(*multi).Elements[idx_user].Playlist, currentWord);
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

void AddSongPlaylist (StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user, PlaylistSong *playlist_song)
{
    printf("\n");
    printf("Daftar Penyanyi :\n");
    for (int index = 0; index < LengthList(artist); index++)
    {
        printf("\t%d. ", index+1);
        DisplayWord(GetList(artist, index));
        printf("\n");
    }
    printf("\n");

    boolean penyanyivalid = false;
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartWordMark();
    printf("\n");
    int i = 0;
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

    if (penyanyivalid)
    {
        Word NamaPenyanyi = currentWord;
        printf("Daftar Album oleh ");
        DisplayWord(NamaPenyanyi);
        printf(" :\n");

        int index = 0;
        for (int i = 0; i < album_artist.Count; i++)
        {
            if (CompareWord1((album_artist).Elements[i].Value, NamaPenyanyi))
            {
                printf("\t%d. ", index+1);
                DisplayWord((album_artist).Elements[i].Key);
                index++;
                printf("\n");
            }
        }
        printf("\n");

        boolean laguvalid = false;
        printf("Masukkan Judul Album yang dipilih : ");
        StartWordMark();
        printf("\n");
        int i = 0;
        while (!laguvalid && (i < album_artist.Count))
        {
            if (CompareWord1((album_artist).Elements[i].Key, currentWord))
            {
                laguvalid = true;
            }
            else
            {
                i++;
            }
        }

        if (laguvalid)
        {
            Word NamaAlbum = currentWord;
            printf("Daftar Lagu Album ");
            DisplayWord(NamaAlbum);
            printf(" oleh ");
            DisplayWord(NamaPenyanyi);
            printf(" :\n");
            int index = 0;
            for (int i = 0; i < song_album.Count; i++)
            {
                if (CompareWord1(song_album.Elements[i].Value, NamaAlbum))
                {
                    printf("\t%d. ", index+1);
                    DisplayWord(song_album.Elements[i].Key);
                    index++;
                    printf("\n");
                }
            }
            printf("\n");

            printf("Masukkan ID Lagu yang dipilih : ");
            StartWordMark();
            printf("\n");
            int ID_Lagu = WordToInt(currentWord);

            if (ID_Lagu > 0 || ID_Lagu <= song_album.Count)
            {
                int check = 0;
                int count = 0;
                while (count < song_album.Count && check < ID_Lagu-1)
                {
                    if (CompareWord1(song_album.Elements[count].Value, NamaAlbum))
                    {
                        check++;
                    }
                    count++;
                }
                Word LaguPilihan = song_album.Elements[count].Key;
                printf("Daftar Playlist Pengguna :\n");
                if (!IsListEmptyDynamic((*multi).Elements[idx_user].Playlist))
                {
                    int index = 0;
                    for (int i = 0; i < LengthListDynamic((*multi).Elements[idx_user].Playlist); i++)
                    {
                        printf("\t%d. ", index+1);
                        DisplayWord(GetDynamic(((*multi).Elements[idx_user].Playlist), i));
                        index++;
                        printf("\n");
                    }
                }
                printf("\n");

                printf("Masukkan ID Playlist yang dipilih : ");
                StartWordMark();
                printf("\n");
                int ID_Playlist = WordToInt(currentWord);

                if (ID_Playlist > 0 || ID_Playlist <= LengthListDynamic((*multi).Elements[idx_user].Playlist))
                {
                    Word PlaylistPilihan = GetDynamic(((*multi).Elements[idx_user].Playlist), ID_Playlist-1);
                    InsVLast(&(*playlist_song).Playlist[ID_Playlist-1].Song, LaguPilihan);
                    printf("Lagu dengan judul \"");
                    DisplayWord(LaguPilihan);
                    printf("\" pada album ");
                    DisplayWord(NamaAlbum);
                    printf(" oleh penyanyi ");
                    DisplayWord(NamaPenyanyi);
                    printf(" berhasil ditambahkan ke dalam playlist ");
                    DisplayWord(PlaylistPilihan);
                    printf(".\n");
                }
                else
                {
                    printf("Playlist tidak ada dalam daftar. Silakan coba lagi.\n");
                }
            }
            else
            {
                printf("Lagu tidak ada dalam daftar. Silakan coba lagi.\n");
            }
        }
        else
        {
            printf("Album ");
            DisplayWord(currentWord);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    }
    else
    {
        printf("Penyanyi ");
        DisplayWord(currentWord);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
    }
}