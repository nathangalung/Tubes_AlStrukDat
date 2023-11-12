#include <stdio.h>

#include "load.h"

void load(Word filename, Set *album, Map *album_artist, Map *song_album, DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist)
{
    StartWordNewline(filename);
    int count_artist = word_to_int(currentWord);

    for (int i=0; i<count_artist; i++)
    {
        int count_album = read_word_count();
        
        Word name_artist = read_line_name();
        
        for (int j=0; j<count_album; j++)
        {
            int count_song = read_word_count();

            Word name_album = read_line_name();
            InsertMap(album_artist, name_album, name_artist);
            InsertSet(album, name_album);

            for (int k=0; k<count_song; k++)
            {                                           
                Word name_song = read_line_name();
                InsertMap(album_artist, name_song, name_album);
            }
        }
    }

    int count_user = read_line_count();

    for(int i=0; i<count_user; i++)
    {
        Word name_user = read_line_name();
        InsertLastDynamic(user, name_user);
    }

    for(int i = 0; i < count_user; i++)
    {
        int count_queue = read_line_count();

        for(int j=0; j<count_queue; j++)
        {
            Word name_queue = read_line_name();
            Enqueue(queue, name_queue);
        }

        int count_history = read_line_count();

        for(int j=0; j<count_history; j++)
        {
            Word name_history = read_line_name();
            PushStack(history, name_history);
        }

        int count_playlist = read_line_count();

        for(int j = 0; j < count_playlist; j++)
        {
            int count_song = read_word_count();
            Word name_playlist = read_line_name();
            InsertLastDynamic(playlist, name_playlist);

            for(int k = 0; k < count_song; k++)
            {
                Word name_song = read_line_name();
            }
        }
    }
}