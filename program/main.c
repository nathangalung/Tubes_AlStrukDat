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
#include "FUNGSI/multi.h"

int main()
{
    Word start_cmp = {"START", 5};
    Word load_cmp = {"LOAD", 4};
    Word login_cmp = {"LOGIN", 5};
    Word logout_cmp = {"LOGOUT", 5};
    Word signup_cmp = {"SIGN UP", 7};
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
    Word test_file = {"config/test.txt", 15};
    Word savefile_file = {"config/savefile.txt", 19};
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
    StaticList playing;

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
    CreateEmptyStatic(&playing);
    InsertLastDynamic(&file, test_file);
    InsertLastDynamic(&file, savefile_file);
    
    boolean run = true;
    boolean menu = false;
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
            if (!menu)
            {
                Start(&count, &artist, &album, &album_artist, &song_album, &user);
                menu = true;
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, load_cmp))
        {
            if (!menu)
            {
                command = SplitWord(command);
                Word filename = ConcatWord(dir, command);
                if (CheckDir(&file, filename))
                {
                    Load(filename, &count, &artist, &album, &album_artist, &song_album, &user, &playing, &queue, &history, &playlist, &playlist_song);
                    printf("Save file berhasil dibaca. WayangWave berhasil dijalankan.\n");
                    menu = true;
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
        else if (CompareWord1(command, signup_cmp))
        {
            if (menu && !sesi)
            {
                SignUp(&user, &queue, &history, &playlist, &playlist_song);
                sesi = true;
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, login_cmp))
        {
            if (menu && !sesi)
            {
                Login(&user, &queue, &history, &playlist, &playlist_song);
                sesi = true;
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, logout_cmp))
        {
            if (sesi)
            {
                Logout(&user, &queue, &history, &playlist, &playlist_song);
                sesi = true;
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
                    ListDefault(artist, album_artist, song_album);
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
                    playSong(artist, album_artist, song_album);
                    printf("play song\n");
                }
                else if (CompareWord1(command, playlist_cmp))
                {
                    playPlaylist(&playlist);
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
            if (sesi)
            {
                sesi = false;

                printf("quit sesi\n");
            }
            else if (sesi)
            {
                menu = false;

                printf("quit menu\n");
            }
            else if (run)
            {
                run = false;

                printf("quit program\n");
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, help_cmp))
        {
            help(sesi, menu);
        }
        else
        {
            printf("Command tidak diketahui!\n");
        }
    }
}