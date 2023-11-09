#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "console.h"

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

    DynamicList playlist;
    Queue queue;
    Stack history;
    Set album;
    Map album_artist;
    Map song_album;
    DynamicList user;

    CreateEmptyDynamic(&user);
    CreateEmptyMap(&album_artist);
    CreateEmptyMap(&song_album);
    CreateEmptySet(&album);
    CreateEmptyQueue(&queue);
    CreateEmptyStack(&history);
    CreateEmptyDynamic(&playlist);
    
    boolean run = true;
    boolean sesi = false;

    while (run)
    {
        printf(">> ");
        StartWordMark();
        IgnoreBlanks();
        IgnoreNewlines();
        Word command = currentWord;

        if (cmp_word_1(command, start_cmp))
        {
            if (!sesi)
            {
                start(&album, &album_artist, &song_album, &user);
                sesi = true;
                printf("start");
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (cmp_word_2(command, load_cmp))
        {
            if (!sesi)
            {
                command = split_word(command);
                Word filename = command;
                load(filename, &album, &album_artist, &song_album, &user, &queue, &history, &playlist);
                sesi = true;
                printf("load");
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (word_cmp_2(command, list_cmp))
        {
            if (sesi)
            {
                command = split_word(command);
                if (word_cmp_1(command, default_cmp))
                {
                    printf("list default berhasil");
                }
                else if (word_cmp_1(command, playlist_cmp))
                {
                    printf("list playlist berhasil");
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
        else if (word_cmp_2(command, play_cmp))
        {
            if (sesi)
            {
                command = split_word(command);
                if (word_cmp_1(command, song_cmp))
                {
                    printf("play song");
                }
                else if (word_cmp_1(command, playlist_cmp))
                {
                    printf("play playlist");
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
        else if (word_cmp_2(command, queue_cmp))
        {
            if (sesi)
            {
                command = split_word(command);
                if (word_cmp_1(command, song_cmp))
                {
                    printf("queue song");
                }
                else if (word_cmp_1(command, playlist_cmp))
                {
                    printf("queue playlist");
                }
                else if (word_cmp_2(command, swap_cmp))
                {
                    command = split_word(command);
                    printf("queue swap");
                    
                }
                else if (word_cmp_2(command, remove_cmp))
                {
                    command = split_word(command);
                    printf("queue remove");
                }
                else if (word_cmp_1(command, clear_cmp))
                {
                    printf("queue clear");
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
        else if (word_cmp_2(command, song_cmp))
        {
            if (sesi)
            {
                command = split_word(command);
                if (word_cmp_1(command, next_cmp))
                {
                    printf("song next");
                }
                else if (word_cmp_1(command, previous_cmp))
                {
                    printf("song previous");
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
        else if (word_cmp_2(command, playlist_cmp))
        {
            if (sesi)
            {
                command = split_word(command);
                if (word_cmp_1(command, create_cmp))
                {
                    printf("playlist create");
                }
                else if (word_cmp_2(command, add_cmp))
                {
                    command = split_word(command);
                    if (word_cmp_1(command, song_cmp))
                    {
                        printf("playlist add song");
                    }
                    else if (word_cmp_1(command, album_cmp))
                    {
                        printf("playlist add album");
                    }
                    else
                    {
                        printf("Command tidak diketahui!\n");
                    }
                }
                else if (word_cmp_2(command, swap_cmp))
                {
                    command = split_word(command);
                    printf("playlist swap");
                }
                else if (word_cmp_2(command, remove_cmp))
                {
                    command = split_word(command);
                    printf("playlist remove");
                }
                else if (word_cmp_1(command, delete_cmp))
                {
                    printf("playlist delete");
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
        else if (word_cmp_1(command, status_cmp))
        {
            if (sesi)
            {
                printf("status");
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (word_cmp_2(command, save_cmp))
        {
            if (sesi)
            {
                command = split_word(command);
                printf("save");

            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (word_cmp_1(command, quit_cmp))
        {
            if (!sesi)
            {
                run = false;

                printf("quit program");
            }
            else if (sesi)
            {
                sesi = false;

                printf("quit sesi");
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (word_cmp_1(command, help_cmp))
        {
            if (!sesi)
            {
                printf("help program");
            }
            else
            {
                printf("help sesi");
            }
        }
        else
        {
            printf("Command tidak diketahui!\n");
        }
    }
}