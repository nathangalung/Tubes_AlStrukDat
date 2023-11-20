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

void status (User multi, StaticList  artist, Set album, StaticList playing,  int idx_user){
    Word currentSong = playing.A[idx_user];
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