#include <stdio.h>
#include <stdlib.h>
#include "status.h"

void DisplayWordDash(Word word, StaticList artist, Set album)
{
    boolean found = false;
    int i = 0;
    while (!found && i < LengthList(artist))
    {
        if (CompareWord(SplitWordLeftMark(word), artist.A[i]))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    if (found)
    {
        DisplayWord(artist.A[i]);
        printf(" - ");
        Word temp = SplitWordMark(word);
        int j = 0;
        while (!CompareWord(SplitWordLeftMark(temp), album.Elements[j]))
        {
            j++;
        }
        DisplayWord(album.Elements[j]);
        printf(" - ");
        temp = SplitWordMark(temp);
        DisplayWord(temp);
    }
    
}
// ========================================================================================= STATUS ======================================================================================================== //
void Status(User multi, StaticList  artist, Set album, DynamicList playing, int idx_user)
{
    boolean found_1 = false;
    int i = 0, j = 0, k = 0, ctr;
    Word currentPlaylist;
    Word currentSong = playing.A[idx_user];
    
    while (!found_1 && i < multi.Elements[idx_user].Playlist.Neff)
    {
        boolean found_2 = false;
        ctr = 0;

        if (Search(multi.Elements[idx_user].PlaylistSong[i].Song, currentSong))
        {
            ctr++;
        }

        while (!found_2 && j < LengthQueue(multi.Elements[idx_user].Queue))
        {
            boolean found_3 = false;

            if (Search(multi.Elements[idx_user].PlaylistSong[i].Song, multi.Elements[idx_user].Queue.Buffer[j]))
            {
                ctr++;
                j++;
            }
            else
            {
                found_2 = true;
            }
        }

        if (!found_2 && NbElmt(multi.Elements[idx_user].PlaylistSong[i].Song) > 0)
        {
            currentPlaylist = multi.Elements[idx_user].Playlist.A[i];
            found_1 = true;
        }
        i++;
    }

    if (found_1 && (ctr >= LengthQueue(multi.Elements[idx_user].Queue)) && LengthQueue(multi.Elements[idx_user].Queue) > 0)
    {
        printf("Current Playlist : \n");
        DisplayWord(currentPlaylist);
        printf("\n\n");
    }

    printf("Now Playing :\n");
    if (CompareStringWord(playing.A[idx_user], "")||CompareStringWord(playing.A[idx_user], "-"))
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
            printf("\t%d. ", (i+1));
            DisplayWordDash(multi.Elements[idx_user].Queue.Buffer[i], artist, album);
            printf("\n");
        }
    }
    else
    {
        printf("Your queue is empty.\n");
    }

    
}