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
    StaticList artist;
    DynamicList playlist;
    Queue queue;
    Stack history;
    Set album;
    Map album_artist;
    Map song_album;
    LinkedList playlist_cont;
    DynamicList user;

    boolean run = true;
    boolean welcome = true;
    boolean sesi = false;

    while (run)
    {
        char *command_str[100];
        char *filename[100];

        printf(">> ");
        gets(command_str);
        Word command = string_to_word(command_str);
        STARTWORD(command);
        if (word_cmp(command, start_cmp))
        {
            if (welcome)
            {
                *filename = "default.txt";
                start(filename, artist, album, song);
                welcome = false;
                sesi = true;
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (word_cmp(command, load_cmp))
        {
            if (welcome)
            {
                filename = Word ;

                split_word(command);
                void load();
                welcome = false;
                sesi = true;
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (word_cmp(command, list_cmp))
        {
            if (sesi)
            {
                split_word(command);
                if (word_cmp(command, default_cmp))
                {
                    void list_default();
                }
                else if (word_cmp(command, playlist_cmp))
                {
                    void list_playlist();
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
        else if (word_cmp(command, play_cmp))
        {
            if (sesi)
            {
                split_word(command);
                if (word_cmp(command, song_cmp))
                {
                    void play_song();
                }
                else if (word_cmp(command, playlist_cmp))
                {
                    void play_playlist();
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
        else if (word_cmp(command, queue_cmp))
        {
            if (sesi)
            {
                split_word(command);
                if (word_cmp(command, song_cmp))
                {
                    void queue_song();
                }
                else if (word_cmp(command, playlist_cmp))
                {
                    void queue_playlist();
                }
                else if (word_cmp(command, swap_cmp))
                {
                    void queue_swap();
                }
                else if (word_cmp(command, remove_cmp))
                {
                    void queue_remove();
                }
                else if (word_cmp(command, clear_cmp))
                {
                    void queue_clear();
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
        else if (word_cmp(command, song_cmp))
        {
            if (sesi)
            {
                split_word(command);
                if (word_cmp(command, next_cmp))
                {
                    void song_next();
                }
                else if (word_cmp(command, previous_cmp))
                {
                    void song_previous();
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
        else if (word_cmp(command, playlist_cmp))
        {
            if (sesi)
            {
                split_word(command);
                if (word_cmp(command, create_cmp))
                {
                    void playlist_create();
                }
                else if (word_cmp(command, add_cmp))
                {
                    if (word_cmp(command, song_cmp))
                    {

                    }
                    else if (word_cmp(command, album_cmp))
                    {

                    }
                    else
                    {
                        printf("Command tidak diketahui!\n");
                    }
                }
                else if (word_cmp(command, swap_cmp))
                {
                    void playlist_swap();
                }
                else if (word_cmp(command, remove_cmp))
                {
                    void playlist_remove();
                }
                else if (word_cmp(command, delete_cmp))
                {
                    void playlist_delete();
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
        else if (word_cmp(command, status_cmp))
        {
            if (sesi)
            {
                void status();
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (word_cmp(command, save_cmp))
        {
            if (sesi)
            {
                void save();
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (word_cmp(command, quit_cmp))
        {
            if (welcome)
            {
                welcome = false;
                run = false;

                void quit_welcome();
            }
            else if (welcome)
            {
                welcome = true;
                sesi = false;

                void quit_sesi();
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (word_cmp(command, help_cmp))
        {
            if (welcome)
            {
                void help_welcome();
            }
            else
            {
                void help_sesi();
            }
        }
        else
        {
            printf("Command tidak diketahui!\n");
        }
    }

    return 0;
}