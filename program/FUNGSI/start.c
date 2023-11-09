#include <stdio.h>

#include "start.h"

void start(Set *album, Map *album_artist, Map *song_album, DynamicList *user)
{
    Word filename = {"FILE_CONFIG/default.txt", 23};
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
                InsertMap(song_album, name_song, name_album);
            }
        }
    }

    int count_user = read_line_count();

    for(int i=0; i<count_user; i++)
    {
        Word name_user = read_line_name();
        InsertLastDynamic(user, name_user);
    }
}