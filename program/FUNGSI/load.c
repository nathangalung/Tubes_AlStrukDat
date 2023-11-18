#include <stdio.h>

#include "load.h"

void load(Word filename, StaticList *count, StaticList *artist, Set *album, Map *album_artist, Map *song_album, DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist)
{
    int count_artist = 0, count_album = 0, count_song = 0, count_user = 0, count_queue = 0, count_history = 0, count_playlist = 0;
    int idx = 0;
    Word name_artist, name_album, name_song, name_user, name_playlist;

    Word dir = {"config/", 7};
    filename = ConcatWord(dir, filename);

    count_artist = ReadCountFirst(filename, artist, idx);
   
    for (int i=0; i<count_artist; i++)
    {
        count_album = ReadCountWord(count, idx);
        
        name_artist = ReadNameLine();
        
        for (int j=0; j<count_album; j++)
        {
            count_song = ReadCountWord(count, idx);
            
            name_album = ReadNameLine();
            InsertSet(album, name_album);
            InsertMap(album_artist, name_album, name_artist);
            
            for (int k=0; k<count_song; k++)
            {                                           
                name_song = ReadNameLine();
                InsertMap(song_album, name_song, name_album);
            }
        }
    }

    count_user = ReadCountLine(count, idx);
    
    for(int i=0; i<count_user; i++)
    {
        name_user = ReadNameLine();
        InsertLastDynamic(user, name_user);
    }

    for(int i = 0; i < count_user; i++)
    {
        count_queue = ReadCountLine(count, idx);

        for(int j=0; j<count_queue; j++)
        {
            name_song = ReadNameLine();
            Enqueue(queue, name_song);
        }

        count_history = ReadCountLine(count, idx);

        for(int j=0; j<count_history; j++)
        {
            name_song = ReadNameLine();
            PushStack(history, name_song);
        }

        count_playlist = ReadCountLine(count, idx);

        for(int j = 0; j < count_playlist; j++)
        {
            count_song = ReadCountWord(count, idx);
            name_playlist = ReadNameLine();
            InsertLastDynamic(playlist, name_playlist);

            for(int k = 0; k < count_song; k++)
            {
                name_song = ReadNameLine();
            }
        }
    }
    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
}