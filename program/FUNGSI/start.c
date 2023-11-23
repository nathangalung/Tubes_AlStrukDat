#include <stdio.h>
#include <stdlib.h>

#include "start.h"
#include "interface.h"

void Start(StaticList *artist, Set *album, Map *album_artist, Map *song_album, DynamicList *user, DynamicList *playing, User *multi)
{
    int count_user = 0, count_artist = 0, count_album = 0, count_song = 0;
    Word name_artist, name_album, name_song, name_user;
    Word filename = {"CONFIG/default.txt", 18};

    CreateEmptyStatic(artist);
    CreateEmptyMap(album_artist);
    CreateEmptyMap(song_album);
    CreateEmptySet(album);
    CreateEmptyDynamic(user);
    CreateEmptyDynamic(playing);

    StartImage();
    
    StartWordNewline(filename);
    count_artist = atoi(currentWord.TabWord);
        
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
    
    for(int i=0; i<count_user; i++)
    {
        name_user = ReadNameLine();
        InsertLastDynamic(user, name_user);
        InsertLastDynamic(playing, StringToWord("-"));
        CreateEmptyQueue(&multi->Elements[i].Queue);
        CreateEmptyStack(&multi->Elements[i].History);
        CreateEmptyDynamic(&multi->Elements[i].Playlist);
    }  
    
    printf("\nFile konfigurasi aplikasi berhasil dibaca. WayangWave88Gacor berhasil dijalankan.\n");
}