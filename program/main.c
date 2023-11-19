#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "FUNGSI/start.h"
#include "FUNGSI/load.h"
#include "FUNGSI/list.h"
#include "FUNGSI/help.h"
#include "FUNGSI/playlist.h"
#include "FUNGSI/play.h"

int main()
{
    Word start_cmp = {"START", 5};
    Word load_cmp = {"LOAD", 4};
    Word list_cmp = {"LIST", 4};
    Word play_cmp = {"PLAY", 4};
    Word queue_cmp = {"QUEUE", 5};
    Word song_cmp = {"SONG", 4};
    Word playlist_cmp = {"PLAYLIST", 8};
    Word status_cmp = {"STATUS", 6};
    Word save_cmp = {"SAVE", 4};
    Word quit_cmp = {"QUIT", 4};
    Word help_cmp = {"HELP", 4};
    Word default_cmp = {"DEFAULT", 7};
    Word swap_cmp = {"SWAP", 4};
    Word remove_cmp = {"REMOVE", 6};
    Word clear_cmp = {"CLEAR", 5};
    Word next_cmp = {"NEXT", 4};
    Word previous_cmp = {"PREVIOUS", 8};
    Word create_cmp = {"CREATE", 6};
    Word add_cmp = {"ADD", 3};
    Word delete_cmp = {"DELETE", 6};
    Word album_cmp = {"ALBUM", 5};
    Word test_file = {"test.txt", 8};
    Word savefile_file = {"savefile.txt", 13};
    Word dir = {"config/", 7};

    DynamicList file;
    StaticList count;
    StaticList artist;
    Stack history;
    Set album;
    Map album_artist;
    Map song_album;
    DynamicList user;
    DynamicList playlist;
    LinierList playlist_song;
    Queue queue;

    CreateEmptyDynamic(&file);
    CreateEmptyStatic(&count);
    CreateEmptyStatic(&artist);
    CreateEmptyMap(&album_artist);
    CreateEmptyMap(&song_album);
    CreateEmptySet(&album);
    CreateEmptyDynamic(&user);
    CreateEmptyQueue(&queue);
    CreateEmptyStack(&history);
    CreateEmptyDynamic(&playlist);
    CreateEmptyLinier(&playlist_song);
    InsertLastDynamic(&file, test_file);
    InsertLastDynamic(&file, savefile_file);
    
    boolean run = true;
    boolean sesi = false;

    while (run)
    {
        printf(">> ");
        StartWordMark();
        IgnoreBlanks();
        IgnoreNewlines();
        Word command = currentWord;

        if (CompareWord1(command, start_cmp))
        {
            if (!sesi)
            {
                start(&count, &artist, &album, &album_artist, &song_album, &user);
                sesi = true;
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, load_cmp))
        {
            if (!sesi)
            {
                command = SplitWord(command);
                Word dir = {"config/", 7};
                Word filename = ConcatWord(dir, command);
                if (CheckDir(&file, filename))
                {
                    load(filename, &count, &artist, &album, &album_artist, &song_album, &user, &queue, &history, &playlist, &playlist_song);
                    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
                    sesi = true;
                }
                else
                {
                    printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
                }
                
                
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, list_cmp))
        {
            if (sesi)
            {
                command = SplitWord(command);
                if (CompareWord1(command, default_cmp))
                {
                    ListDefault(&artist, &album_artist, &song_album);
                    printf("list default berhasil\n");
                }
                else if (CompareWord1(command, playlist_cmp))
                {
                    ListPlaylist(&playlist);
                    printf("list playlist berhasil\n");
                }
                else
                {
                    printf("Command tidak diketahui!\n");
                }
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, play_cmp))
        {
            if (sesi)
            {
                command = SplitWord(command);
                if (CompareWord1(command, song_cmp))
                {
                    playSong(album_artist, album, song_album);
                    printf("play song\n");
                }
                else if (CompareWord1(command, playlist_cmp))
                {
                    playPlaylist(playlist_song);
                    printf("play playlist\n");
                }
                else
                {
                    printf("Command tidak diketahui!\n");
                }
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, queue_cmp))
        {
            if (sesi)
            {
                command = SplitWord(command);
                if (CompareWord1(command, song_cmp))
                {
                    printf("queue song\n");
                }
                else if (CompareWord1(command, playlist_cmp))
                {
                    printf("queue playlist\n");
                }
                else if (CompareWord2(command, swap_cmp))
                {
                    command = SplitWord(command);
                    printf("queue swap\n");
                    
                }
                else if (CompareWord2(command, remove_cmp))
                {
                    command = SplitWord(command);
                    printf("queue remove\n");
                }
                else if (CompareWord1(command, clear_cmp))
                {
                    printf("queue clear\n");
                }
                else
                {
                    printf("Command tidak diketahui!\n");
                }
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, song_cmp))
        {
            if (sesi)
            {
                command = SplitWord(command);
                if (CompareWord1(command, next_cmp))
                {
                    printf("song next\n");
                }
                else if (CompareWord1(command, previous_cmp))
                {
                    printf("song previous\n");
                }
                else
                {
                    printf("Command tidak diketahui!\n");
                }
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, playlist_cmp))
        {
            if (sesi)
            {
                command = SplitWord(command);
                if (CompareWord1(command, create_cmp))
                {
                    CreatePlaylist(&playlist);
                    printf("playlist create\n");
                }
                else if (CompareWord2(command, add_cmp))
                {
                    command = SplitWord(command);
                    if (CompareWord1(command, song_cmp))
                    {
                        printf("playlist add song\n");
                    }
                    else if (CompareWord1(command, album_cmp))
                    {
                        printf("playlist add album\n");
                    }
                    else
                    {
                        printf("Command tidak diketahui!\n");
                    }
                }
                else if (CompareWord2(command, swap_cmp))
                {
                    command = SplitWord(command);
                    printf("playlist swap\n");
                }
                else if (CompareWord2(command, remove_cmp))
                {
                    command = SplitWord(command);
                    printf("playlist remove\n");
                }
                else if (CompareWord1(command, delete_cmp))
                {
                    printf("playlist delete\n");
                }
                else
                {
                    printf("Command tidak diketahui!\n");
                }
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, status_cmp))
        {
            if (sesi)
            {
                printf("status\n");
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, save_cmp))
        {
            if (sesi)
            {
                command = SplitWord(command);
                printf("save\n");
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, quit_cmp))
        {
            if (!sesi)
            {
                run = false;

                printf("quit program\n");
            }
            else if (sesi)
            {
                sesi = false;

                printf("quit sesi\n");
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, help_cmp))
        {
            help(sesi);
        }
        else
        {
            printf("Command tidak diketahui!\n");
        }
    }
}