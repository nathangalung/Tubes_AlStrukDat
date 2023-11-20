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

void Enhance(StaticList artist, Map song_album, Map album_artist, User multi, PlaylistSong *playlist_song, int idx_user)
{
    time_t t;
    srand((unsigned int)time(&t));

    printf("Berikut daftar playlist yang dimiliki :\n");
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
        printf("Silakan masukkan ID playlist yang ingin dienhance : ");
        StartWordMark();
        idx_playlist = WordToInt(currentWord) - 1;
        
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
    int rand_count = (rand() % 3) + 1, ctr = 0;

    for (int i = 0; i < rand_count; i++)
    {
        address P = First(playlist_song->Playlist[idx_user].Song);
        while (!found_2)
        {
            int rand_song = rand() % (song_album.Count + 1);

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
                DisplayWord(song_album.Elements[rand_song].Key);
                found_2 = true;
                int i = 0, j = 0;
                
                Word MarkWord = {";", 1};
                Word input = ConcatWord(song_album.Elements[rand_song].Key, MarkWord);
                input = ConcatWord(input, song_album.Elements[rand_song].Value);
                input = ConcatWord(input, MarkWord);
                DisplayWord(input);
                printf("\ncheck1\n");
                printf("check2\n");
                printf("check3\n");
                input = ConcatWord(input, album_artist.Elements[j].Value);
                
                InsVLast(&playlist_song->Playlist[idx_playlist].Song, input);

                printf("Berhasil menambahkan lagu ");
                DisplayWord(input);
                printf(" ke dalam ID playlist %d.\n", (idx_playlist+1));
            }
        }
    }
}