#include <stdio.h>
#include <stdlib.h>

#include "load.h"

void Load(Word filename, StaticList *artist, Set *album, Map *album_artist, Map *song_album, DynamicList *user, StaticList *playing, User *multi, boolean *menu)
{
    boolean found = false;
    int count_artist = 0, count_album = 0, count_song = 0, count_user = 0, count_queue = 0, count_history = 0, count_playlist = 0;
    int ctr = 0;
    Word name_artist, name_album, name_song, name_user, name_playlist, name_playing;

    CreateEmptyStatic(artist);
    CreateEmptyMap(album_artist);
    CreateEmptyMap(song_album);
    CreateEmptySet(album);
    CreateEmptyDynamic(user);
    CreateEmptyStatic(playing);
    CreateEmptyUser(multi);
    
    count_artist = ReadCountFirst(filename);

    for (int i=0; i<count_artist; i++)
    {
        count_album = ReadCountWord();
        
        name_artist = ReadNameLine();
        artist->A[i] = name_artist;
        
        for (int j=0; j<count_album; j++)
        {
            count_song = ReadCountWord();

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
    count_user = ReadCountLine();
    
    for (int i=0; i<count_user; i++)
    {
        name_user = ReadNameLine();
        InsertLastDynamic(user, name_user);
        CreateEmptyQueue(&multi->Elements[i].Queue);
        CreateEmptyStack(&multi->Elements[i].History);
        CreateEmptyDynamic(&multi->Elements[i].Playlist);
    }

    Stack temp_stack;
    Word temp_word;
    CreateEmptyStack(&temp_stack);

    for (int i = 0; i < count_user; i++)
    {
        name_playing = ReadNameLine();
        playing->A[i] = name_playing;
        
        count_queue = ReadCountLine();

        for (int j=0; j<count_queue; j++)
        {
            name_song = ReadNameLine();
            Enqueue(&multi->Elements[i].Queue, name_song);
        } 
        
        count_history = ReadCountLine();

        for (int j=0; j<count_history; j++)
        {
            name_song = ReadNameLine();
            PushStack(&temp_stack, name_song);
        }

        for (int j=0; j<count_history; j++)
        {
            PopStack(&temp_stack, &temp_word);
            PushStack(&multi->Elements[i].History, temp_word);
        }

        count_playlist = ReadCountLine();

        for(int j = 0; j < count_playlist; j++)
        {
            count_song = ReadCountWord();
            name_playlist = ReadNameLine();
            InsertLastDynamic(&multi->Elements[i].Playlist, name_playlist);
            CreateEmptyLinier(&multi->Elements[i].PlaylistSong[j].Song);

            for(int k = 0; k < count_song; k++)
            {
                name_song = ReadNameLine();
                InsVLast(&multi->Elements[i].PlaylistSong[j].Song, name_song);
            }
        }
    }
    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
    *menu = true;
    
}