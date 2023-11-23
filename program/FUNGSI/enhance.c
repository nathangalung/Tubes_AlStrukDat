#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "enhance.h"

unsigned int rng(unsigned int max)
{
    time_t t;
    srand((unsigned int)time(&t));
    static unsigned int seed = 0;
    seed = (seed << 3) + (unsigned int)time(NULL) + rand() + (unsigned int)pow(seed, 2) + (unsigned int)sqrt(seed);

    return (seed % (max)) + 1;
}
// ========================================================================================= ENHANCE ======================================================================================================== //
void Enhance(StaticList artist, Set album, Map song_album, Map album_artist, User multi, int idx_user)
{
    printf("Berikut daftar playlist yang dimiliki :\n");
    for (int i = 0; i < (LengthListDynamic(multi.Elements[idx_user].Playlist)); i++)
    {
        printf("\t%d. ", (i+1));
        DisplayWord(multi.Elements[idx_user].Playlist.A[i]);
        printf("\n");
    }

    boolean found_1 = false;
    int idx_playlist;

    printf("\nSilakan masukkan ID playlist yang ingin dienhance : ");
    StartWordMark();
    idx_playlist = atoi(currentWord.TabWord) - 1;
    
    if (idx_playlist >= 0 && idx_playlist < LengthListDynamic(multi.Elements[idx_user].Playlist))
    {
        found_1 = true;
    }
    else
    {
        printf("\nID playlist %d tidak terdapat pada daftar playlist.\n", (idx_playlist + 1));
    }

    if (found_1)
    {
        unsigned int rand_count = rng(3);
        
        for (int i = 0; i < rand_count; i++)
        {
            boolean found_2 = false;
            Word input, MarkSC = {";", 1};

            while (!found_2)
            {
                boolean found_3 = false;
                unsigned int rand_song = rng(song_album.Count), ctr = 0;
                address P = First(multi.Elements[idx_user].PlaylistSong[idx_playlist].Song);
                
                while (!found_3 && ctr < NbElmt(multi.Elements[idx_user].PlaylistSong[idx_playlist].Song))
                {
                    if (CompareWord(SplitWordMark(SplitWordMark(Info(P))), song_album.Elements[rand_song].Key))
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
                    
                    while (!CompareWord(song_album.Elements[rand_song].Value, album_artist.Elements[i].Key))
                    {
                        i++;
                    }

                    input = ConcatWord(album_artist.Elements[i].Value, MarkSC);
                    input = ConcatWord(input, song_album.Elements[rand_song].Value);
                    input = ConcatWord(input, MarkSC);
                    input = ConcatWord(input, song_album.Elements[rand_song].Key);
                    
                    InsVLast(&multi.Elements[idx_user].PlaylistSong[idx_playlist].Song, input);

                    printf("\nBerhasil menambahkan lagu ");
                    DisplayWord(song_album.Elements[rand_song].Key);
                    printf(" oleh ");
                    DisplayWord(album_artist.Elements[i].Value);
                    printf(" ke dalam ID playlist %d.\n", (idx_playlist + 1));
                }
            }
        }
    }
}