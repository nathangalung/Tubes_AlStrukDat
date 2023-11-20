#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "enhance.h"

int randint(int n)
{
    if ((n - 1) == RAND_MAX)
    {
        return rand();
    }
    else
    {
        int end = RAND_MAX / n;
        end *= n;
        int r;
        while ((r = rand()) >= end);

        return r % n;
    }
}

void Enhance(Map song_album, User multi, PlaylistSong *playlist_song, int idx_user)
{
    printf("Berikut daftar playlist yang dimiliki :\n");
    for (int i = 0; i < (LengthListDynamic(multi.Elements[idx_user].Playlist)); i++)
    {
        printf("\t%d. ", (i+1));
        DisplayWord(multi.Elements[idx_user].Playlist.A[i]);
        printf("\n");
    }

    boolean found_1 = false;

    while (!found_1)
    {
        printf("Silakan masukkan ID playlist yang ingin dienhance : ");
        StartWordMark();
        
        if ((WordToInt(currentWord) - 1) < LengthListDynamic(multi.Elements[idx_user].Playlist))
        {
            found_1 = true;
        }
        else
        {
            printf("ID playlist %d tidak terdapat pada daftar playlist\n", WordToInt(currentWord));
        }
    }

    boolean found_2 = false, found_3 = false;
    int rand_count = randint(3), ctr = 0;

    for (int i = 0; i < rand_count; i++)
    {
        address P = First(playlist_song->Playlist[idx_user].Song);
        while (!found_2)
        {
            int rand_song = randint(song_album.Count);

            while (!found_3 && ctr < LengthListDynamic(multi.Elements[idx_user].Playlist))
            {
                if (CompareWord1(SplitWordMark(SplitWordMark(Info(P))), song_album.Elements[rand_song].Key))
                {
                    found_3 = true;
                }
                else
                {
                    ctr++;
                    P = Next(P);
                }
            }
            if (!found_3)
            {
                found_2 = true;
                InsVLast(&playlist_song->Playlist[(WordToInt(currentWord))-1].Song, song_album.Elements[rand_song].Key);
                printf("Berhasil menambahkan lagu ");
                DisplayWord(song_album.Elements[rand_song].Key);
                printf(" ke dalam ID playlist %d.\n", (WordToInt(currentWord)));
            }
        }
    }
    address Q = First(playlist_song->Playlist[idx_user].Song);
    for (int i = 0; i < NbElmt(playlist_song->Playlist[WordToInt(currentWord)-1].Song); i++)
    {
        DisplayWord(Info(Q));
        printf("\n");
        Q = Next(Q);
    }
}