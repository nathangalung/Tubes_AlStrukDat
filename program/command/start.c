#include <stdio.h>

#include "start.h"

void start(List artist, Set album, Map album_artist, Map song_album, List user)
{
    int count_artist, count_album, count_song, count_user;
    Word name_artist, name_album, name_song;

    StartWordFile("../FILE_CONFIG/default.txt");
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
}