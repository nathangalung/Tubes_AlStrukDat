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

void enhance(Map song_album, User multi, PlaylistSong *playlist_song, int idx_user)
{
    printf("Berikut list playlist yang tertera :\n");
    for (int i = 0; i < (LengthListDynamic(multi.Elements[idx_user].Playlist)); i++)
    {
        printf("%d ", (i+1));
        DisplayWord(multi.Elements[idx_user].Playlist.A[i]);
        printf("\n");
    }

    boolean found = false;
    int ctr = 0;

    while (!found)
    {
        printf("Silakan masukkan ID playlist yang ingin dienchance : ");
        StartWordMark();
        
        while (!found && ctr < LengthListDynamic(multi.Elements[idx_user].Playlist))
        {
            if (CompareWord1(currentWord, multi.Elements[idx_user].Playlist.A[ctr]))
            {
                found = true;
            }
            else
            {
                ctr++;
            }
        }
        printf("%d\n", ctr);
    }
}