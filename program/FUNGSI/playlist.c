#include <stdio.h>
#include <stdlib.h>
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
        printf("\n");
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
            InsertLastDynamic(&multi->Elements[idx_user].Playlist, currentWord);
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

void AddSongPlaylist (StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user)
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
                Word LaguPilihan = song_album.Elements[count].Key;
                printf("Daftar Playlist Pengguna :\n");
                if (!IsListEmptyDynamic(multi->Elements[idx_user].Playlist))
                {
                    int index = 0;
                    for (int i = 0; i < LengthListDynamic(multi->Elements[idx_user].Playlist); i++)
                    {
                        printf("\t%d. ", index+1);
                        DisplayWord(GetDynamic((multi->Elements[idx_user].Playlist), i));
                        index++;
                        printf("\n");
                    }
                }
                printf("\n");

                printf("Masukkan ID Playlist yang dipilih : ");
                StartWordMark();
                printf("\n");
                int ID_Playlist = atoi(currentWord.TabWord);

                if (ID_Playlist > 0 && ID_Playlist <= LengthListDynamic(multi->Elements[idx_user].Playlist))
                {
                    Word PlaylistPilihan = GetDynamic((multi->Elements[idx_user].Playlist), ID_Playlist-1);
                    Word MarkSC = {";", 1};
                    Word Pilihan = ConcatWord(NamaPenyanyi, MarkSC);
                    Pilihan = ConcatWord(Pilihan, NamaAlbum);
                    Pilihan = ConcatWord(Pilihan, MarkSC);
                    Pilihan = ConcatWord(Pilihan, LaguPilihan);
                    InsVLast(&multi->Elements[idx_user].PlaylistSong[ID_Playlist-1].Song, Pilihan);
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

void AddAlbumPlaylist (StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user)
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
            printf("Daftar Playlist Pengguna :\n");
            if (!IsListEmptyDynamic(multi->Elements[idx_user].Playlist))
            {
                int index = 0;
                for (int i = 0; i < LengthListDynamic(multi->Elements[idx_user].Playlist); i++)
                {
                    printf("\t%d. ", index+1);
                    DisplayWord(GetDynamic((multi->Elements[idx_user].Playlist), i));
                    index++;
                    printf("\n");
                }
            }
            printf("\n");

            printf("Masukkan ID Playlist yang dipilih : ");
            StartWordMark();
            printf("\n");
            int ID_Playlist = atoi(currentWord.TabWord);

            if (ID_Playlist > 0 && ID_Playlist <= LengthListDynamic(multi->Elements[idx_user].Playlist))
            {
                for (int i = 0; i < song_album.Count; i++)
                {
                    if (CompareWord1(song_album.Elements[i].Value, NamaAlbum))
                    {
                        Word MarkSC = {";", 1};
                        Word LaguPilihan = song_album.Elements[i].Key;
                        Word Pilihan = ConcatWord(NamaPenyanyi, MarkSC);
                        Pilihan = ConcatWord(Pilihan, NamaAlbum);
                        Pilihan = ConcatWord(Pilihan, MarkSC);
                        Pilihan = ConcatWord(Pilihan, LaguPilihan);
                        InsVLast(&multi->Elements[idx_user].PlaylistSong[ID_Playlist-1].Song, Pilihan);
                    }
                }
                Word PlaylistPilihan = GetDynamic((multi->Elements[idx_user].Playlist), ID_Playlist-1);
                printf("Album dengan judul \"");
                DisplayWord(NamaAlbum);
                printf("\" berhasil ditambahkan ke dalam playlist pengguna \"");
                DisplayWord(PlaylistPilihan);
                printf("\".\n");
            }
            else
            {
                printf("Playlist tidak ada dalam daftar. Silakan coba lagi.\n");
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

void SwapPlaylist (User *multi, int idx_user, Word word)
{
    printf("\n");
    int count = 0;
    int ID_Playlist = atoi(SplitWordLeftBlank(word).TabWord);
    DisplayWord(SplitWordLeftBlank(word));
    Word Split1 = SplitWordLeftBlank(word);
    int idx_1 = atoi(SplitWordBlank(Split1).TabWord);
    Word Split2 = SplitWordBlank(word);
    int idx_2 = atoi(SplitWordBlank(Split2).TabWord);
    address Song1, Song2, temp;
    printf("%d, %d, %d\n", ID_Playlist, idx_1, idx_2);

    if ((ID_Playlist > 0) && (ID_Playlist  <= LengthListDynamic((*multi).Elements[idx_user].Playlist)))
    {
        Word PlaylistPilihan = GetDynamic(((*multi).Elements[idx_user].Playlist), ID_Playlist-1);
        if ((idx_1 >= 1 && idx_1 <= NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song)) && (idx_2 >= 1 && idx_2 <= NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song)))
        {
            Song1 = First((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song);
            Song2 = First((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song);
            for (int i = 0; i < idx_1 - 1; i++)
            {
                Song1 = Next(Song1);
            }
            for (int i = 0; i < idx_2 - 1; i++)
            {
                Song2 = Next(Song2);
            }
            Word InfoSong1 = Info(Song1);
            Word InfoSong2 = Info(Song2);

            temp = Next(Song1);
            Next(Song1) = Next(Song2);
            Next(Song2) = temp;

            printf("Berhasil menukar lagu dengan nama \"");
            DisplayWord(SplitWordMark(SplitWordMark(InfoSong1)));
            printf("\" dengan \"");
            DisplayWord(SplitWordMark(SplitWordMark(InfoSong2)));
            printf("\" di playlist \"");
            DisplayWord(PlaylistPilihan);
            printf("\"\n");
        }
        else if (idx_1 == 0 || idx_2 == 0)
        {
            printf("Tidak ada lagu dengan urutan ke 0 di playlist \"");
            DisplayWord(PlaylistPilihan);
            printf("\"\n");
        }
        else if ((idx_1 < 0 || idx_1 > NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song)) && (idx_2 < 0 || idx_2 > NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song)))
        {
            printf("Tidak ada lagu dengan urutan %d dan %d di playlist \"", idx_1, idx_2);
            DisplayWord(PlaylistPilihan);
            printf("\"\n");
        }
        else if ((idx_1 < 0 || idx_1 > NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song)))
        {
            printf("Tidak ada lagu dengan urutan %d di playlist \"", idx_1);
            DisplayWord(PlaylistPilihan);
            printf("\"\n");
        }
        else
        {
            printf("Tidak ada lagu dengan urutan %d di playlist \"", idx_2);
            DisplayWord(PlaylistPilihan);
            printf("\"\n");
        }
    }
    else
    {
        printf("Tidak ada playlist dengan playlist ID %d\n", ID_Playlist);
    }
}

void RemovePlaylist (User *multi, int idx_user, Word word)
{
    int ID_Playlist = atoi(SplitWordLeftBlank(word).TabWord);
    int ID_Lagu = atoi(SplitWordBlank(word).TabWord);
    address Song;
    printf("\n");

    if ((ID_Playlist > 0) && (ID_Playlist <= LengthListDynamic((*multi).Elements[idx_user].Playlist)))
    {
        Word PlaylistPilihan = GetDynamic(((*multi).Elements[idx_user].Playlist), ID_Playlist-1);
        if (ID_Lagu >= 1 && ID_Lagu <= NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song))
        {
            Song = First((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song);
            for (int i = 0; i < ID_Lagu - 1; i++)
            {
                Song = Next(Song);
            }
            Word DeletedSong = Info(Song);
            DelP (&(*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song, DeletedSong);

            printf("Lagu \"");
            DisplayWord(SplitWordMark(SplitWordMark(DeletedSong)));
            printf("\" oleh \"");
            DisplayWord(SplitWordLeftMark(DeletedSong));
            printf("\" telah dihapus dari playlist \"");
            DisplayWord(PlaylistPilihan);
            printf("\"!\n");
        }
    }
    else
    {
        printf("Tidak ada playlist dengan playlist ID %d\n", ID_Playlist);
    }

    address P = First(multi->Elements[idx_user].PlaylistSong[ID_Playlist-1].Song);
    for (int i = 0; i < NbElmt(multi->Elements[idx_user].PlaylistSong[ID_Playlist-1].Song); i++)
    {
        DisplayWord(Info(P));
        printf("\n");
        P = Next(P);
    }
}