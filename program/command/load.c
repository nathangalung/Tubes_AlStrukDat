#include <stdio.h>

#include "load.h"
#include "../console.h"

void load(char *filename, Set album, Map album_artist, Map song_album, List user, Queue *queue, Stack *history, DynamicList *playlist)
{
    int count_artist, count_album, count_song, count_user, count_queue, count_history, count_playlist;
    Word name_artist, name_album, name_song, name_playlist;

    StartWordFile(concat("../FILE_CONFIG/", filename));
    count_artist = word_to_int(currentWord);

    for (int i=0; i<count_artist; i++)
    {
        AdvWordInput();
        count_album = word_to_int(currentWord);
        AdvWordFile();
        name_artist = currentWord;
        artist.A[i] = name_artist;

        for (int j=0; j<count_album; j++)
        {
            AdvWordInput();
            count_song = word_to_int(currentWord);
            AdvWordFile();
            name_album = currentWord;
            Insert(&album_artist, name_album, name_artist);

            for (int k=0; k<count_song; k++)
            {
                AdvWordFile();
                name_song = currentWord;
                Insert(&song_album, name_song, name_album);
            }
        }
    }

    AdvWordFile();
    count_user = word_to_int(currentWord);

    for(int i=0; i<count_user; i++)
    {
        AdvWordFile();
        user.A[i] = currentWord;
        user.Neff++;
    }

    for(int i=0; i<count_user; i++)
    {
        AdvWordFile();
        count_queue = word_to_int(currentWord);

        for(int j=0; j<count_queue; j++)
        {
            AdvWordFile();
            enqueue(&queue, currentWord);
        }

        AdvWordFile();
        count_history = word_to_int(currentWord);

        for(int j=0; j<count_history; j++)
        {
            AdvWordFile();
            push();
        }

        AdvWordFile();
        count_playlist = word_to_int(currentWord);

        for(int j=0; j<count_playlist; j++)
        {
            AdvWordInput();
            count_song = word_to_int(currentWord);
            AdvWordFile();
            name_playlist = currentWord;
            playlist.A[j] = name_playlist;
            playlist.Neff++;

            for(int k=0; k<count_song; k++)
            {
                AdvWordFile();
                name_song = currentWord;
            }
        }
    }
}