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

void Enhance(StaticList artist, Set album, Map song_album, Map album_artist, User multi, PlaylistSong *playlist_song, int idx_user)
{
    time_t t;
    srand((unsigned int)time(&t));

    printf("\nBerikut daftar playlist yang dimiliki :\n");
    for (int i = 0; i < (LengthListDynamic(multi.Elements[idx_user].Playlist)); i++)
    {
        printf("\t%d. ", (i+1));
        DisplayWord(multi.Elements[idx_user].Playlist.A[i]);
        printf("\n");
    }

    boolean found_1 = false;
    int idx_playlist;

    while (!found_1)
    {
        printf("\nSilakan masukkan ID playlist yang ingin dienhance : ");
        StartWordMark();
        idx_playlist = WordToInt(currentWord) - 1;
        
        if ((WordToInt(currentWord) - 1) < LengthListDynamic(multi.Elements[idx_user].Playlist))
        {
            found_1 = true;
        }
        else
        {
            printf("\nID playlist %d tidak terdapat pada daftar playlist.\n", WordToInt(currentWord));
        }
    }

    int rand_count = (rand() % 3) + 1;

    for (int i = 0; i < rand_count; i++)
    {
        boolean found_2 = false;
        address P = First(playlist_song->Playlist[idx_user].Song);
        Word input, Dash = {" - ", 3};

        while (!found_2)
        {
            boolean found_3 = false;
            int rand_song = rand() % (song_album.Count + 1), ctr = 0;;

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
                int i = 0, j = 0;
                
                while (!CompareWord1(song_album.Elements[rand_song].Value, album_artist.Elements[i].Key))
                {
                    i++;
                }

                input = ConcatWord(album_artist.Elements[i].Value, Dash);
                input = ConcatWord(input, song_album.Elements[rand_song].Value);
                input = ConcatWord(input, Dash);
                input = ConcatWord(input, song_album.Elements[rand_song].Key);
                
                InsVLast(&playlist_song->Playlist[idx_playlist].Song, input);

                printf("\nBerhasil menambahkan lagu ");
                DisplayWord(song_album.Elements[rand_song].Key);
                printf(" oleh ");
                DisplayWord(album_artist.Elements[i].Value);
                printf(" ke dalam ID playlist %d.\n", (idx_playlist+1));
            }
        }
    }
}