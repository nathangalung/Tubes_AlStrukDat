/* file queue.c */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// ========================================================================================= QUEUE SONG ======================================================================================================== //

void QueueSong(StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user)
{

    /* KAMUS LOKAL */
    int index, idlagu;
    Word penyanyi, album_word, lagu;

    /* ALGORITMA */
    printf("Daftar Penyanyi :\n");
    for (index = 0; index < LengthStatic(artist); index++)
    {
        printf("\t%d. ", index + 1);
        DisplayWord(GetStatic(artist, index));
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
    while (!penyanyivalid && (i < LengthStatic(artist)))
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
            int ID_Lagu = WordToInt(currentWord);

            if (ID_Lagu > 0 && ID_Lagu <= index)
            {
                int check = 0;
                int count = 0;
                while (count < song_album.Count && check < ID_Lagu)
                {
                    if (CompareWord(song_album.Elements[count].Value, NamaAlbum))
                    {
                        check++;
                    }
                    count++;
                }
                Word MarkSC = {";", 1};
                Word LaguPilihan = song_album.Elements[count - 1].Key;
                Word Pilihan = ConcatWord(NamaPenyanyi, MarkSC);
                Pilihan = ConcatWord(Pilihan, NamaAlbum);
                Pilihan = ConcatWord(Pilihan, MarkSC);
                Pilihan = ConcatWord(Pilihan, LaguPilihan);

                Enqueue(&multi->Elements[idx_user].Queue, Pilihan);

                printf("Berhasil menambahkan lagu \"");
                DisplayWord(LaguPilihan);
                printf("\" oleh \"");
                DisplayWord(NamaPenyanyi);
                printf("\" ke queue.\n");
            }
            else
            {
                printf("%sLagu tidak ada dalam daftar. Silakan coba lagi!\n", RED);
            }
        }
        else
        {
            printf("%sAlbum ", RED);
            DisplayWord(currentWord);
            printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
        }
    }
    else
    {
        printf("%sPenyanyi ", RED);
        DisplayWord(currentWord);
        printf(" tidak ada dalam daftar. Silakan coba lagi.\n");
    }
}

// ========================================================================================= QUEUE PLAYLIST ======================================================================================================== //

void QueuePlaylist(User *multi, int idx_user)
{
    
    /* KAMUS LOKAL */
    int idPlaylist, i;
    address lagu;
    boolean idPlaylistValid;
    Word Playlist;

    /* ALGORITMA */
    if (!IsEmptyDynamic(multi->Elements[idx_user].Playlist))
    {
        printf("Daftar Playlist Pengguna :\n");
        for (int i = 0; i < LengthDynamic(multi->Elements[idx_user].Playlist); i++)
        {
            printf("\t%d. ", i+1);
            DisplayWord(GetDynamic((multi->Elements[idx_user].Playlist), i));
            printf("\n");
        }
        printf("\nMasukkan ID Playlist yang dipilih : ");
        StartWordMark();
        Playlist = currentWord;
        idPlaylist = WordToInt(currentWord);

        if (idPlaylist > 0 && idPlaylist <= LengthDynamic(multi->Elements[idx_user].Playlist))
        {
            printf("\nBerhasil menambahkan playlist \"");
            DisplayWord(GetDynamic(multi->Elements[idx_user].Playlist, idPlaylist-1));
            printf("\" ke queue.\n");

            lagu = First(multi->Elements[idx_user].PlaylistSong[idPlaylist - 1].Song);
            for (i = 0; i < NbElmt(multi->Elements[idx_user].PlaylistSong[idPlaylist - 1].Song); i++)
            {
                Enqueue(&multi->Elements[idx_user].Queue, Info(lagu));
                lagu = Next(lagu);
            }
        }
        else
        {
            printf("%s\nPlaylist tidak ada dalam daftar. Silakan coba lagi!\n", RED);
        }
    }
    else
    {
        printf("%sKamu tidak memiliki playlist. Silakan buat terlebih dahulu!\n", RED);
    }
}

// ========================================================================================= QUEUE SWAP ======================================================================================================== //

void QueueSwap(User *multi, Word word, int idx_user)
{
    int ctr = 0;
    int idx_1 = WordToInt(SplitWordLeftBlank(word)), idx_2 = WordToInt(SplitWordBlank(word));
    Word temp;

    if ((idx_1 >= 1 && idx_1 <= LengthQueue(multi->Elements[idx_user].Queue)) && (idx_2 >= 1 && idx_2 <= LengthQueue(multi->Elements[idx_user].Queue)))
    {
        if (idx_1 == idx_2)
        {
            printf("Tidak dapat menukar lagu dengan urutan yang sama.\n");
        }
        else
        {
            temp = multi->Elements[idx_user].Queue.Buffer[idx_1 - 1];
            multi->Elements[idx_user].Queue.Buffer[idx_1 - 1] = multi->Elements[idx_user].Queue.Buffer[idx_2 - 1];
            multi->Elements[idx_user].Queue.Buffer[idx_2 - 1] = temp;

            printf("Lagu \"");
            DisplayWord(SplitWordMark(SplitWordMark(multi->Elements[idx_user].Queue.Buffer[idx_2 - 1])));
            printf("\" berhasil ditukar dengan \"");
            DisplayWord(SplitWordMark(SplitWordMark(multi->Elements[idx_user].Queue.Buffer[idx_1 - 1])));
            printf("\"\n");
        }
    }
    else if (idx_1 == 0 || idx_2 == 0)
    {
        printf("%sTidak ada lagu dengan urutan ke 0. Silakan sertakan urutan yang valid dari lagu yang ingin ditukar!\n", RED);
    }
    else if (idx_1 < 0 || idx_2 < 0)
    {
        printf("ID Lagu invalid.\n");
    }
    else if ((idx_1 > LengthQueue(multi->Elements[idx_user].Queue)) && (idx_2 > LengthQueue(multi->Elements[idx_user].Queue)))
    {
        printf("%sLagu dengan urutan ke %d dan %d tidak terdapat dalam queue!\n", RED, idx_1, idx_2);
    }
    else if (idx_1 > LengthQueue(multi->Elements[idx_user].Queue))
    {
        printf("%sLagu dengan urutan ke %d tidak terdapat dalam queue!\n", RED, idx_1);
    }
    else
    {
        printf("%sLagu dengan urutan ke %d tidak terdapat dalam queue!\n", RED, idx_2);
    }
}

// ========================================================================================= QUEUE REMOVE ======================================================================================================== //

void QueueRemove(User *multi, Word word, int idx_user)
{
    int ctr = 0;
    int idx_1 = atoi(word.TabWord);
    Word song = multi->Elements[idx_user].Queue.Buffer[idx_1 - 1];

    if (idx_1 > 0 && idx_1 <= LengthQueue(multi->Elements[idx_user].Queue))
    {
        if (IDX_HEAD(multi->Elements[idx_user].Queue) == IDX_TAIL(multi->Elements[idx_user].Queue))
        {
            IDX_HEAD(multi->Elements[idx_user].Queue) = IDX_UNDEF;
            IDX_TAIL(multi->Elements[idx_user].Queue) = IDX_UNDEF; 
        }
        else
        {
            for (int i = (idx_1 - 1); i < (LengthQueue(multi->Elements[idx_user].Queue) - 1); i++)
            {
                multi->Elements[idx_user].Queue.Buffer[i] = multi->Elements[idx_user].Queue.Buffer[i + 1];
                ctr++;
            }
            IDX_TAIL(multi->Elements[idx_user].Queue) = LengthQueue(multi->Elements[idx_user].Queue) - 2;

        }
        Word artist = SplitWordLeftMark(song);
        song = SplitWordMark(SplitWordMark(song));
        printf("Lagu \"");
        DisplayWord(artist);
        printf("\" oleh \"");
        DisplayWord(song);
        printf("\" telah dihapus dari queue!\n");
    }
    else if (idx_1 == 0)
    {
        printf("%sTidak ada lagu dengan urutan ke 0. Silakan sertakan urutan yang valid dari lagu yang ingin ditukar!\n", RED);
    }
    else
    {
        printf("%sLagu dengan urutan ke %d tidak terdapat dalam queue!\n", RED, idx_1);
    }
}

// ========================================================================================= QUEUE CLEAR ======================================================================================================== //

void QueueClear(User *multi, int idx_user)
{
    CreateEmptyQueue(&multi->Elements[idx_user].Queue);
    printf("Queue berhasil dikosongkan.\n");
}