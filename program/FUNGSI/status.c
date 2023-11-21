#include <stdio.h>
#include <stdlib.h>
#include "status.h"

void DisplayWordDash(Word word, StaticList artist, Set album)
{
    int i = 0;
    while (!CompareWord3(word, artist.A[i]))
    {
        i++;
    }
    DisplayWord(artist.A[i]);
    printf(" - ");
    Word temp = SplitWordMark(word);
    int j = 0;
    while (!CompareWord3(temp, album.Elements[j]))
    {
        j++;
    }
    DisplayWord(album.Elements[j]);
    printf(" - ");
    temp = SplitWordMark(temp);
    DisplayWord(temp);
}

void status(User multi, StaticList  artist, Set album, StaticList playing, int idx_user)
{
    boolean found_1 = false;
    int i = 0, j = 0, k = 0;
    Word currentPlaylist;
    Word currentSong = playing.A[idx_user];
    
    while (!found_1 && i < multi.Elements[idx_user].Playlist.Neff)
    {
        boolean found_2 = false;
        address P = First(multi.Elements[idx_user].PlaylistSong[i].Song);

        while (!found_2 && j < NbElmt(multi.Elements[idx_user].PlaylistSong[i].Song))
        {
            boolean found_3 = false;

            while (!found_3 && k < LengthQueue(multi.Elements[idx_user].Queue))
            {
                if (CompareWord1(multi.Elements[idx_user].Queue.Buffer[k], Info(P)))
                {
                    found_3 = true;
                }
                else
                {
                    k++;
                }
            }
            if (found_3)
            {
                P = Next(P);
            }
            else
            {
                found_2 = true;
            }
            j++;
        }

        if (!found_2 && NbElmt(multi.Elements[idx_user].PlaylistSong[i].Song) > 0)
        {
            currentPlaylist = multi.Elements[idx_user].Playlist.A[i];
            found_1 = true;
        }
        i++;
    }
    if (found_1)
    {
        printf("\nCurrent Playlist: ");
        DisplayWord(currentPlaylist);
        printf("\n");
    }

    printf("\nNow Playing:\n");
    if (CompareStringWord(playing.A[idx_user], MarkStatic))
    {
        printf("No songs have been played yet. Please search for a song to begin playback.\n");
    }
    else 
    {
        DisplayWordDash(currentSong, artist, album);
        printf("\n");

    }

    printf("\nQueue :\n");
    if (!IsQueueEmpty(multi.Elements[idx_user].Queue))
    {
        for (int i = 0; i < LengthQueue(multi.Elements[idx_user].Queue); i++)
        {
            printf("%d. ", (i+1));
            DisplayWordDash(multi.Elements[idx_user].Queue.Buffer[i], artist, album);
            printf("\n");
        }
    }
    else
    {
        printf("Your queue is empty.\n");
    }

    
}