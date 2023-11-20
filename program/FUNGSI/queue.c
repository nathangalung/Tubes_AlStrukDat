/* file queue.c */

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void queueSong(StaticList artist, Map album_artist, Map song_album, User *multi, StaticList *playing, int idx_user)
{

    /* KAMUS LOKAL */
    int index, idlagu;
    Word penyanyi, album_word, lagu;

    /* ALGORITMA */
    printf("\n");
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

        boolean albumvalid = false;
        printf("Masukkan Judul Album yang dipilih : ");
        StartWordMark();
        printf("\n");
        int i = 0;
        while (!albumvalid && (i < album_artist.Count))
        {
            if (CompareWord1((album_artist).Elements[i].Key, currentWord) && CompareWord1((album_artist).Elements[i].Value, NamaPenyanyi))
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
            int ID_Lagu = atoi(currentWord.TabWord);
            if (ID_Lagu > 0 && ID_Lagu <= index)
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
                Word MarkSC = {";", 1};
                Word LaguPilihan = song_album.Elements[count].Key;
                Word Pilihan = ConcatWord(NamaPenyanyi, MarkSC);
                Pilihan = ConcatWord(Pilihan, NamaAlbum);
                Pilihan = ConcatWord(Pilihan, MarkSC);
                Pilihan = ConcatWord(Pilihan, LaguPilihan);

                Enqueue(&multi->Elements[idx_user].Queue, Pilihan);

                printf("Berhasil menambahkan lagu \"");
                DisplayWord(LaguPilihan);
                printf("\" oleh \"");
                DisplayWord(NamaPenyanyi);
                printf("\"ke queue\n");
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

void queuePlaylist(User multi, StaticList *playing, int idx_user, PlaylistSong playlist_song){
    
    /* KAMUS LOKAL */
    int idPlaylist, i;
    address lagu;
    boolean idPlaylistValid;
    Word Playlist;

    /* ALGORITMA */
    printf("\nMasukkan ID Playlist: ");
    StartWordMark();
    Playlist = currentWord;
    idPlaylist = atoi(currentWord.TabWord);

    idPlaylistValid = false;

    if (!idPlaylistValid)
    {
        if (IsListEmptyDynamic(multi.Elements[idx_user].Playlist) || idPlaylist < 0 || idPlaylist > LengthListDynamic(multi.Elements[idx_user].Playlist))
        {
            printf("\nPlaylist tidak ditemukan.\n");
        }
        else
        {
            idPlaylistValid = true;
            printf("\nBerhasil menambahkan playlist \"");
            DisplayWord(GetDynamic(multi.Elements[idx_user].Playlist, idPlaylist-1));
            printf("\" ke queue.\n");

            lagu = First(playlist_song.Playlist[idPlaylist - 1].Song);
            for (i = 0; i < NbElmt(playlist_song.Playlist[idPlaylist - 1].Song); i++)
            {
                Enqueue(&multi.Elements[idx_user].Queue, Info(lagu));
                lagu = Next(lagu);
            }
        }
    }
}

void queueSwap(User *multi, Word word, int idx_user)
{
    int ctr = 0;
    int idx_1 = atoi(SplitWordLeft(word).TabWord), idx_2 = atoi(SplitWordBlank(word).TabWord);
    Word temp;

    if ((idx_1 >= 1 && idx_1 <= LengthQueue(multi->Elements[idx_user].Queue)) && (idx_2 >= 1 && idx_2 <= LengthQueue(multi->Elements[idx_user].Queue)))
    {
        temp = multi->Elements[idx_user].Queue.Buffer[idx_1 - 1];
        multi->Elements[idx_user].Queue.Buffer[idx_1 - 1] = multi->Elements[idx_user].Queue.Buffer[idx_2 - 1];
        multi->Elements[idx_user].Queue.Buffer[idx_2 - 1] = temp;

        printf("\nLagu \"");
        DisplayWord(SplitWordMark(SplitWordMark(multi->Elements[idx_user].Queue.Buffer[idx_1 - 1])));
        printf("\" berhasil ditukar dengan \"");
        DisplayWord(SplitWordMark(SplitWordMark(multi->Elements[idx_user].Queue.Buffer[idx_2 - 1])));
        printf("\"\n");
    }
    else if (idx_1 == 0 || idx_2 == 0)
    {
        printf("\nTidak ada lagu dengan urutan ke 0. Silakan sertakan urutan yang valid dari lagu yang ingin ditukar!\n");
    }
    else if ((idx_1 < 0 || idx_1 > LengthQueue(multi->Elements[idx_user].Queue)) && (idx_2 < 0 || idx_2 > LengthQueue(multi->Elements[idx_user].Queue)))
    {
        printf("\nLagu dengan urutan ke %d dan %d tidak terdapat dalam queue!\n", idx_1, idx_2);
    }
    else if (idx_1 < 0 || idx_1 > LengthQueue(multi->Elements[idx_user].Queue))
    {
        printf("\nLagu dengan urutan ke %d tidak terdapat dalam queue!\n", idx_1);
    }
    else
    {
        printf("\nLagu dengan urutan ke %d tidak terdapat dalam queue!\n", idx_2);
    }
}

void queueRemove(User *multi, Word word, int idx_user)
{
    int ctr = 0;
    int idx_1 = atoi(word.TabWord);
    Word song = multi->Elements[idx_user].Queue.Buffer[idx_1 - 1];

    if (idx_1 > 0 && idx_1 < LengthQueue(multi->Elements[idx_user].Queue))
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
                multi->Elements[idx_user].Queue.Buffer[i] = multi->Elements[idx_user].Queue.Buffer[i];
            }
        }
        Word artist = SplitWordLeft(song);
        song = SplitWordMark(SplitWordMark(song));
        printf("\nLagu \"");
        DisplayWord(artist);
        printf("\" oleh \"");
        DisplayWord(song);
        printf("\" telah dihapus dari queue!\n");
    }
    else if (idx_1 == 0)
    {
        printf("\nTidak ada lagu dengan urutan ke 0. Silakan sertakan urutan yang valid dari lagu yang ingin ditukar!\n");
    }
    else
    {
        printf("\nLagu dengan urutan ke %d tidak terdapat dalam queue!\n", idx_1);
    }
}

void queueClear(User *multi, int idx_user)
{
    CreateEmptyQueue(&multi->Elements[idx_user].Queue);
    printf("\nQueue berhasil dikosongkan.\n");
}