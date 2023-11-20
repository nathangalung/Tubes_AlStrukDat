#include <stdio.h>

#include "load.h"

void Load(Word filename, StaticList *count, StaticList *artist, Set *album, Map *album_artist, Map *song_album, DynamicList *user, StaticList *playing, User *multi, PlaylistSong *playlist_song)
{
    int count_artist = 0, count_album = 0, count_song = 0, count_user = 0, count_queue = 0, count_history = 0, count_playlist = 0;
    int idx = 0;
    Word name_artist, name_album, name_song, name_user, name_playlist, name_playing;
    
    Word check = {"config/test.txt", 15};
    count_artist = ReadCountFirst(check, count, idx);
    idx++;
    
    for (int i=0; i<count_artist; i++)
    {
        count_album = ReadCountWord(count, idx);
        idx++;
        
        name_artist = ReadNameLine();
        artist->A[i] = name_artist;
        
        for (int j=0; j<count_album; j++)
        {
            count_song = ReadCountWord(count, idx);
            idx++;
            
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
    idx++;
    
    for(int i=0; i<count_user; i++)
    {
        name_user = ReadNameLine();
        InsertLastDynamic(user, name_user);
    }

    for(int i = 0; i < count_user; i++)
    {
        name_playing = ReadNameLine();
        playing->A[i] = name_playing;
        
        count_queue = ReadCountLine(count, idx);
        idx++;

        CreateEmptyQueue(&(*multi).Elements[i].Queue);
        for(int j=0; j<count_queue; j++)
        {
            name_song = ReadNameLine();
            Enqueue(&(*multi).Elements[i].Queue, name_song);
        } 

        count_history = ReadCountLine(count, idx);
        idx++;

        CreateEmptyStack(&(*multi).Elements[i].History);
        for(int j=0; j<count_history; j++)
        {
            name_song = ReadNameLine();
            PushStack(&(*multi).Elements[i].History, name_song);
        }

        count_playlist = ReadCountLine(count, idx);
        idx++;

        CreateEmptyDynamic(&(*multi).Elements[i].Playlist);
        for(int j = 0; j < count_playlist; j++)
        {
            count_song = ReadCountWord(count, idx);
            idx++;
            name_playlist = ReadNameLine();
            InsertLastDynamic(&(*multi).Elements[i].Playlist, name_playlist);

            CreateEmptyLinier(&(*playlist_song).Playlist[j].Song);
            for(int k = 0; k < count_song; k++)
            {
                name_song = ReadNameLine();
                InsVLast(&(*playlist_song).Playlist[j].Song, name_song);
            }
        }
    }
}