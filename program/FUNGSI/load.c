#include <stdio.h>

#include "load.h"

void load(Word filename, Set *album, Map *album_artist, Map *song_album, DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist)
{
    int count_artist = 0, count_album = 0, count_song = 0, count_user = 0, count_queue = 0, count_history = 0, count_playlist = 0;
    Word name_artist, name_album, name_song, name_user, name_playlist;

    Word dir = {"FILE_CONFIG/", 12};
    filename = concat(dir, filename);

    StartWordNewline(filename);
    count_artist = word_to_int(currentWord);

    for (int i=0; i<count_artist; i++)
    {
        count_album = read_word_count();
        
        name_artist = read_line_name();
        
        for (int j=0; j<count_album; j++)
        {
            count_song = read_word_count();

            name_album = read_line_name();
            InsertMap(album_artist, name_album, name_artist);
            InsertSet(album, name_album);

            for (int k=0; k<count_song; k++)
            {                                           
                name_song = read_line_name();
                InsertMap(song_album, name_song, name_album);
            }
        }
    }

    for (int i = 0; i<LengthQueue(*queue); i++)
    {
    }

    for (int i = 0; i<LengthQueue(*queue); i++)
    {
    }


    for (int i = 0; i<LengthQueue(*queue); i++)
    {
    }

    count_user = read_line_count();

    for(int i=0; i<count_user; i++)
    {
        name_user = read_line_name();
        InsertLastDynamic(user, name_user);
    }

    for(int i = 0; i < count_user; i++)
    {
        count_queue = read_line_count();

        for(int j=0; j<count_queue; j++)
        {
            name_song = read_line_name();
            Enqueue(queue, name_song);
        }

        count_history = read_line_count();

        for(int j=0; j<count_history; j++)
        {
            name_song = read_line_name();
            PushStack(history, name_song);
        }

        count_playlist = read_line_count();

        for(int j = 0; j < count_playlist; j++)
        {
            count_song = read_word_count();
            name_playlist = read_line_name();
            InsertLastDynamic(playlist, name_playlist);

            for(int k = 0; k < count_song; k++)
            {
                name_song = read_line_name();
            }
        }
    }
    printf("load lama berhasil\n");
}