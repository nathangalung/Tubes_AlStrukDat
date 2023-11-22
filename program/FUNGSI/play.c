/* file play.c */

#include <stdio.h>
#include <stdlib.h>
#include "play.h"

void PlaySong(StaticList artist, Map album_artist, Map song_album, User *multi, StaticList *playing, int idx_user)
{

    /* KAMUS LOKAL */
    int index, idlagu;
    Word penyanyi, album_word, lagu;

    /* ALGORITMA */
    printf("Daftar Penyanyi :\n");
    for (index = 0; index < LengthList(artist); index++)
    {
        printf("\t%d. ", index + 1);
        DisplayWord(GetList(artist, index));
        printf("\n");
    }
    printf("\n");

    boolean penyanyivalid = false;
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    StartWordMark();
    printf("\n");

    penyanyi = currentWord;
    penyanyivalid = false;

    int i = 0;
    while (!penyanyivalid && (i < LengthList(artist)))
    {
        if (CompareWord(artist.A[i], currentWord))
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
            if (CompareWord((album_artist).Elements[i].Value, NamaPenyanyi))
            {
                printf("\t%d. ", index+1);
                DisplayWord((album_artist).Elements[i].Key);
                index++;
                printf("\n");
            }
        }
        printf("\n");

        boolean albumvalid = false;
        printf("Masukkan Judul Album yang dipilih : ");
        StartWordMark();
        printf("\n");
        int i = 0;
        while (!albumvalid && (i < album_artist.Count))
        {
            if (CompareWord((album_artist).Elements[i].Key, currentWord) && CompareWord((album_artist).Elements[i].Value, NamaPenyanyi))
            {
                albumvalid = true;
            }
            else
            {
                i++;
            }
        }

        if (albumvalid)
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
                if (CompareWord(song_album.Elements[i].Value, NamaAlbum))
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
            int ID_Lagu = atoi(currentWord.TabWord);
            if (ID_Lagu > 0 && ID_Lagu <= index)
            {
                int check = 0;
                int count = 0;
                while (count < song_album.Count && check <= ID_Lagu)
                {
                    if (CompareWord(song_album.Elements[count].Value, NamaAlbum))
                    {
                        check++;
                    }
                    count++;
                }
                Word MarkSC = {";", 1};
                Word LaguPilihan = song_album.Elements[count - 2].Key;
                Word Pilihan = ConcatWord(NamaPenyanyi, MarkSC);
                Pilihan = ConcatWord(Pilihan, NamaAlbum);
                Pilihan = ConcatWord(Pilihan, MarkSC);
                Pilihan = ConcatWord(Pilihan, LaguPilihan);

                playing->A[idx_user] = Pilihan;
                CreateEmptyQueue(&multi->Elements[idx_user].Queue);
                CreateEmptyStack(&multi->Elements[idx_user].History);

                printf("Berhasil menambahkan lagu \"");
                DisplayWord(LaguPilihan);
                printf("\" oleh \"");
                DisplayWord(NamaPenyanyi);
                printf("\" ke queue.\n");
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

void PlayPlaylist(User *multi, StaticList *playing, int idx_user)
{
    /* KAMUS LOKAL */
    int idPlaylist;
    boolean idPlaylistValid;
    address lagu;
    Word namaplaylist;
    
    /* ALGORITMA */
    printf("Masukkan ID Playlist: ");
    StartWordMark();
    namaplaylist = currentWord;
    idPlaylist = atoi(currentWord.TabWord);

    if (idPlaylist > 0 && idPlaylist <= LengthListDynamic(multi->Elements[idx_user].Playlist))
    {
        idPlaylistValid = true;
        printf("\nMemutar playlist \"");
        DisplayWord(GetDynamic(multi->Elements[idx_user].Playlist, idPlaylist-1));
        printf("\".\n");
        
        playing->A[idx_user] = StringToWord(MarkStatic);
        lagu = First(multi->Elements[idx_user].PlaylistSong[idPlaylist-1].Song);
        
        Stack temp_stack;
        Word temp_word;

        CreateEmptyStack(&temp_stack);
        CreateEmptyQueue(&multi->Elements[idx_user].Queue);
        CreateEmptyStack(&multi->Elements[idx_user].History);
        
        if (!IsEmptyLinier(multi->Elements[idx_user].PlaylistSong[idPlaylist-1].Song))
        {
            playing->A[idx_user] = Info(lagu);
            lagu = Next(lagu);

            for (int i = 0; (i < NbElmt(multi->Elements[idx_user].PlaylistSong[idPlaylist-1].Song) - 1); i++)
            {
                PushStack(&temp_stack, Info(lagu));
                Enqueue(&multi->Elements[idx_user].Queue, Info(lagu));
                lagu = Next(lagu);
            }
            
            for (int i = 0; (i < NbElmt(multi->Elements[idx_user].PlaylistSong[idPlaylist-1].Song) - 1); i++)
            {
                PopStack(&temp_stack, &temp_word);
                PushStack(&multi->Elements[idx_user].History, temp_word);
            }
        }
        else
        {
            printf("\nPlaylist %d tidak memiliki lagu", idPlaylist);
        }
    }
    else
    {
        printf("\nPlaylist tidak ditemukan.\n");
    }
}