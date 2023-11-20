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

void status(User multi, StaticList  artist, Set album, StaticList playing, PlaylistSong playlist_song, int idx_user)
{
    boolean found_1 = false, found_2 = false;
    int i = 0, j = 0;
    Word currentPlaylist;
    Word currentSong = playing.A[idx_user];
    while (!found_1 && i < multi.Elements[idx_user].Playlist.Neff)
    {
        address P = First(playlist_song.Playlist[i].Song);
        while (!found_2 && j < NbElmt(playlist_song.Playlist[i].Song))
        {
            if (!CompareWord1(currentSong, Info(P)))
            {
                found_2 = true;
            }
            else
            {
                P = Next(P);
            }
        }

        if (!found_2)
        {
            currentPlaylist = multi.Elements[idx_user].Playlist.A[i];
            found_1 = true;
        }
    }
    if (found_1)
    {
        printf("Current Playlist: ");
        DisplayWord(currentPlaylist);
        printf("\n");
    }

    printf("Now Playing:\n");
    if (CompareStringWord(playing.A[idx_user], MarkStatic))
    {
        printf("No songs have been played yet. Please search for a song to begin playback.");
    }
    else 
    {
        DisplayWordDash(currentSong, artist, album);
        printf("\n");

    }

    printf("\nQueue :\n");
    for (int i = 0; i < LengthQueue(multi.Elements[idx_user].Queue); i++){
        printf("%d. ", (i+1));
        DisplayWordDash(multi.Elements[idx_user].Queue.Buffer[i], artist, album);
        printf("\n");
    }

    
}