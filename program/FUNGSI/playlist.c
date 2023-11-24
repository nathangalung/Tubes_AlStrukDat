#include <stdio.h>
#include <stdlib.h>
#include "playlist.h"

// ========================================================================================= PLAYLIST CREATE ======================================================================================================== //

void PlaylistCreate(User *multi, int idx_user)
{
    int countChar = 0;

    printf("Masukkan nama playlist yang ingin dibuat : ");
    StartWordMark();
    printf("\n");
    
    for (int i = 0; i < currentWord.Length; i++) 
    {
        if (currentWord.TabWord[i] != BLANK) 
        {
            countChar++;
        }
    }

    if ((countChar >= 3)) 
    {
        CreateEmptyLinier(&multi->Elements[idx_user].PlaylistSong[LengthDynamic(multi->Elements[idx_user].Playlist)].Song);
        InsertLastDynamic(&multi->Elements[idx_user].Playlist, currentWord);
        printf("Playlist \"");
        DisplayWord(currentWord);
        printf("\" berhasil dibuat!\n");
        printf("\nSilakan masukkan lagu-lagu artis terkini kesayangan Anda!\n");
    } 
    else 
    {
        printf("%sMinimal terdapat 3 karakter selain spasi dalam nama playlist. Silakan coba lagi!\n", RED);
    }
}
// ========================================================================================= PLAYLIST ADD SONG ======================================================================================================== //
void PlaylistAddSong(StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user)
{
    if (!IsEmptyDynamic(multi->Elements[idx_user].Playlist))
    {
        printf("Daftar Penyanyi :\n");
        for (int index = 0; index < LengthStatic(artist); index++)
        {
            printf("\t%d. ", index+1);
            DisplayWord(GetStatic(artist, index));
            printf("\n");
        }
        printf("\n");

        boolean penyanyivalid = false;
        printf("Masukkan Nama Penyanyi yang dipilih : ");
        StartWordMark();
        printf("\n");
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
                    Word LaguPilihan = song_album.Elements[count - 1].Key;
                    printf("Daftar Playlist Pengguna :\n");
                    if (!IsEmptyDynamic(multi->Elements[idx_user].Playlist))
                    {
                        for (int i = 0; i < LengthDynamic(multi->Elements[idx_user].Playlist); i++)
                        {
                            printf("\t%d. ", i+1);
                            DisplayWord(GetDynamic((multi->Elements[idx_user].Playlist), i));
                            printf("\n");
                        }
                    }
                    printf("\n");

                    printf("Masukkan ID Playlist yang dipilih : ");
                    StartWordMark();
                    printf("\n");
                    int ID_Playlist = WordToInt(currentWord);

                    if (ID_Playlist > 0 && ID_Playlist <= LengthDynamic(multi->Elements[idx_user].Playlist))
                    {
                        Word PlaylistPilihan = GetDynamic((multi->Elements[idx_user].Playlist), ID_Playlist-1);
                        Word MarkSC = {";", 1};
                        Word Pilihan = ConcatWord(NamaPenyanyi, MarkSC);
                        Pilihan = ConcatWord(Pilihan, NamaAlbum);
                        Pilihan = ConcatWord(Pilihan, MarkSC);
                        Pilihan = ConcatWord(Pilihan, LaguPilihan);
                        address P = First((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song);
                        boolean LaguSudahAda = false;
                        int count = 0;
                        while (!LaguSudahAda && count < NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song))
                        {
                            if (CompareWord(SplitWordMark(SplitWordMark(Info(P))), LaguPilihan))
                            {
                                LaguSudahAda = true;
                            }
                            else
                            {
                                count++;
                                P = Next(P);
                            }
                        }
                        if (!LaguSudahAda)
                        {
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
                            printf("%sLagu ", RED);
                            DisplayWord(LaguPilihan);
                            printf(" sudah ada di playlist ");
                            DisplayWord(PlaylistPilihan);
                            printf(".\n");
                        }
                    }
                    else
                    {
                        printf("%sPlaylist tidak ada dalam daftar. Silakan coba lagi!\n", RED);
                    }
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
                printf(" tidak ada dalam daftar. Silakan coba lagi!\n");
            }
        }
        else
        {
            printf("%sPenyanyi ", RED);
            DisplayWord(currentWord);
            printf(" tidak ada dalam daftar. Silakan coba lagi!\n");
        }
    }
    else
    {
        printf("%sKamu tidak memiliki playlist. Silakan buat terlebih dahulu!\n", RED);
    }
}

// ========================================================================================= PLAYLIST ADD ALBUM ======================================================================================================== //

void PlaylistAddAlbum (StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user)
{
    if (!IsEmptyDynamic(multi->Elements[idx_user].Playlist))
    {
        printf("Daftar Penyanyi :\n");
        for (int index = 0; index < LengthStatic(artist); index++)
        {
            printf("\t%d. ", index+1);
            DisplayWord(GetStatic(artist, index));
            printf("\n");
        }
        printf("\n");

        boolean penyanyivalid = false;
        printf("Masukkan Nama Penyanyi yang dipilih : ");
        StartWordMark();
        printf("\n");
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
                printf("Daftar Playlist Pengguna :\n");
                if (!IsEmptyDynamic(multi->Elements[idx_user].Playlist))
                {
                    for (int i = 0; i < LengthDynamic(multi->Elements[idx_user].Playlist); i++)
                    {
                        printf("\t%d. ", i+1);
                        DisplayWord(GetDynamic((multi->Elements[idx_user].Playlist), i));
                        printf("\n");
                    }
                }
                printf("\n");

                printf("Masukkan ID Playlist yang dipilih : ");
                StartWordMark();
                printf("\n");
                int ID_Playlist = WordToInt(currentWord);

                int count1 = 0;
                int count2 = 0;
                if (ID_Playlist > 0 && ID_Playlist <= LengthDynamic(multi->Elements[idx_user].Playlist))
                {
                    for (int i = 0; i < song_album.Count; i++)
                    {
                        if (CompareWord(song_album.Elements[i].Value, NamaAlbum))
                        {
                            count1++;
                            Word MarkSC = {";", 1};
                            Word LaguPilihan = song_album.Elements[i].Key;
                            Word Pilihan = ConcatWord(NamaPenyanyi, MarkSC);
                            Pilihan = ConcatWord(Pilihan, NamaAlbum);
                            Pilihan = ConcatWord(Pilihan, MarkSC);
                            Pilihan = ConcatWord(Pilihan, LaguPilihan);
                            if (!SearchLinier((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song, Pilihan))
                            {
                                InsVLast(&multi->Elements[idx_user].PlaylistSong[ID_Playlist-1].Song, Pilihan);
                            }
                            else
                            {
                                count2++;
                            }
                        }
                    }
                    Word PlaylistPilihan = GetDynamic((multi->Elements[idx_user].Playlist), ID_Playlist-1);
                    if (count2 == 0)
                    {
                        printf("Album dengan judul \"");
                        DisplayWord(NamaAlbum);
                        printf("\" berhasil ditambahkan ke dalam playlist pengguna \"");
                        DisplayWord(PlaylistPilihan);
                        printf("\".\n");
                    }
                    else if (count1 != count2)
                    {
                        printf("Beberapa lagu dari album \"");
                        DisplayWord(NamaAlbum);
                        printf("\" berhasil ditambahkan ke dalam playlist pengguna \"");
                        DisplayWord(PlaylistPilihan);
                        printf("\".\n");
                    }
                    else
                    {
                        printf("Album dengan judul \"");
                        DisplayWord(NamaAlbum);
                        printf("\" sudah ada dalam playlist pengguna \"");
                        DisplayWord(PlaylistPilihan);
                        printf("\".\n");
                    }
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
    else
    {
        printf("Kamu tidak memiliki playlist. Silakan buat terlebih dahulu!\n");
    }
}

// ========================================================================================= PLAYLIST SWAP ======================================================================================================== //

void PlaylistSwap(User *multi, int idx_user, Word word)
{
    if (!IsEmptyDynamic(multi->Elements[idx_user].Playlist))
    {
        int ID_Playlist = WordToInt(SplitWordLeftBlank(word));
        Word ID_Lagu = SplitWordBlank(word), ID_Lagu2 = SplitWordBlank(ID_Lagu);
        int idx_1 = WordToInt(SplitWordLeftBlank(ID_Lagu)), idx_2 = WordToInt(ID_Lagu2);
        address Song1, Song2, PrevSong1, PrevSong2, NextSong1, NextSong2, temp;

        if ((ID_Playlist > 0) && (ID_Playlist  <= LengthDynamic((*multi).Elements[idx_user].Playlist)))
        {
            Word PlaylistPilihan = GetDynamic(((*multi).Elements[idx_user].Playlist), ID_Playlist-1);
            if ((idx_1 >= 1 && idx_1 <= NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song)) && (idx_2 >= 1 && idx_2 <= NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song)))
            {
                if (idx_1 == idx_2)
                {
                    printf("Tidak dapat menukar lagu dengan urutan yang sama.\n");
                }
                else
                {
                    PrevSong1 = NULL;
                    Song1 = First((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song);
                    for (int i = 0; i < idx_1 - 1; i++)
                    {
                        PrevSong1 = Song1;
                        Song1 = Next(Song1);
                    }
                    Word InfoSong1 = Info(Song1);
                    
                    PrevSong2 = NULL;
                    Song2 = First((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song);
                    for (int i = 0; i < idx_2 - 1; i++)
                    {
                        PrevSong2 = Song2;
                        Song2 = Next(Song2);
                    }
                    Word InfoSong2 = Info(Song2);

                    if (PrevSong1 != NULL)
                    {
                        Next(PrevSong1) = Song2;
                    }
                    else
                    {
                        First((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song) = Song2;
                    }

                    if (PrevSong2 != NULL)
                    {
                        Next(PrevSong2) = Song1;
                    }
                    else
                    {
                        First((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song) = Song1;
                    }

                    temp = Next(Song2);
                    Next(Song2) = Next(Song1);
                    Next(Song1) = temp;

                    printf("Berhasil menukar lagu dengan nama \"");
                    DisplayWord(SplitWordMark(SplitWordMark(InfoSong1)));
                    printf("\" dengan \"");
                    DisplayWord(SplitWordMark(SplitWordMark(InfoSong2)));
                    printf("\" di playlist \"");
                    DisplayWord(PlaylistPilihan);
                    printf("\"\n");
                }   
            }
            else if (idx_1 == 0 || idx_2 == 0)
            {
                printf("Tidak ada lagu dengan urutan ke 0 di playlist \"");
                DisplayWord(PlaylistPilihan);
                printf("\"\n");
            }
            else if (idx_1 < 0 || idx_2 < 0)
            {
                printf("ID Lagu invalid.\n");
            }
            else if ((idx_1 > NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song)) && (idx_2 > NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song)))
            {
                printf("Tidak ada lagu dengan urutan %d dan %d di playlist \"", idx_1, idx_2);
                DisplayWord(PlaylistPilihan);
                printf("\"\n");
            }
            else if ((idx_1 > NbElmt((*multi).Elements[idx_user].PlaylistSong[ID_Playlist-1].Song)))
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
    else
    {
        printf("Kamu tidak memiliki playlist. Silakan buat terlebih dahulu!\n");
    }
}

// ========================================================================================= PLAYLIST REMOVE ======================================================================================================== //

void PlaylistRemove(User *multi, int idx_user, Word word)
{
    if (!IsEmptyDynamic(multi->Elements[idx_user].Playlist))
    {
        int ID_Playlist = WordToInt(SplitWordLeftBlank(word)), ID_Lagu = WordToInt(SplitWordBlank(word));
        address Song;

        if ((ID_Playlist > 0) && (ID_Playlist <= LengthDynamic((*multi).Elements[idx_user].Playlist)))
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
            else
            {
                printf("Tidak ada lagu dengan urutan %d di playlist \"", ID_Lagu);
                DisplayWord(PlaylistPilihan);
                printf("\"!\n");
            }
        }
        else
        {
            printf("Tidak ada playlist dengan playlist ID %d\n", ID_Playlist);
        }
    }
    else
    {
        printf("Kamu tidak memiliki playlist. Silakan buat terlebih dahulu!\n");
    }
}

void PlaylistDelete(User *multi, int idx_user)
{
    if (!IsEmptyDynamic(multi->Elements[idx_user].Playlist))
    {
        printf("Daftar Playlist Pengguna :\n");
        if (!IsEmptyDynamic(multi->Elements[idx_user].Playlist))
        {
            int index = 0;
            for (int i = 0; i < LengthDynamic(multi->Elements[idx_user].Playlist); i++)
            {
                printf("\t%d. ", index+1);
                DisplayWord(GetDynamic((multi->Elements[idx_user].Playlist), i));
                index++;
                printf("\n");
            }
        }
        printf("\n");

        printf("Masukkan ID Playlist yang dipilih : ");
        StartWordBlank();
        printf("\n");
        int ID_Playlist = atoi(currentWord.TabWord);

        if (ID_Playlist > 0 && ID_Playlist <= LengthDynamic(multi->Elements[idx_user].Playlist))
        {
            Word PlaylistPilihan = GetDynamic((multi->Elements[idx_user].Playlist), ID_Playlist-1);
            if (ID_Playlist == LengthDynamic(multi->Elements[idx_user].Playlist))
            {
                multi->Elements[idx_user].Playlist.Neff--;
            }
            else
            {
                for (int i = ID_Playlist-1; i <= LengthDynamic(multi->Elements[idx_user].Playlist); i++)
                {
                    multi->Elements[idx_user].Playlist.A[i] = multi->Elements[idx_user].Playlist.A[i+1];
                }
                multi->Elements[idx_user].Playlist.Neff--;
            }
            CreateEmptyLinier(&multi->Elements[idx_user].PlaylistSong[ID_Playlist-1].Song);

            printf("Playlist ID %d dengan judul \"", ID_Playlist);
            DisplayWord(PlaylistPilihan);
            printf("\" berhasil dihapus.\n");
        }
        else
        {
            ("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.\n", ID_Playlist);
        }
    }
    else
    {
        printf("Kamu tidak memiliki playlist. Silakan buat terlebih dahulu!\n");
    }
}