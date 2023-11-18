#include <stdio.h>

#include "start.h"

void start(StaticList *count, StaticList *artist, Set *album, Map *album_artist, Map *song_album, DynamicList *user)
{
    int count_artist = 0, count_album = 0, count_song = 0, count_user = 0;
    int idx = 0;
    Word name_artist, name_album, name_song, name_user;

    Word filename = {"config/default.txt", 23};
    
    count_artist = ReadCountFirst(filename, count, idx);
        
    for (int i=0; i<count_artist; i++)
    {
        count_album = ReadCountWord(count, idx);
        
        name_artist = ReadNameLine();
        artist->A[i] = name_artist;

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
    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
}