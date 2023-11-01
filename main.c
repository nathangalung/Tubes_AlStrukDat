#include <stdio.h>

#include "console.h"

int main()
{
    Word start = {"START", 5};
    Word load = {"LOAD", 4};
    Word list = {"LIST", 4};
    Word play = {"PLAY", 4};
    Word queue = {"QUEUE", 5};
    Word song = {"SONG", 4};
    Word playlist = {"PLAYLIST", 8};
    Word status = {"STATUS", 6};
    Word save = {"SAVE", 4};
    Word quit = {"QUIT", 4};
    Word help = {"HELP", 4};
    Word defaults = {"DEFAULT", 7};
    Word playlist = {"PLAYLIST", 8};
    Word swap = {"SWAP", 4};
    Word remove = {"REMOVE", 6};
    Word clear = {"CLEAR", 5};
    Word next = {"NEXT", 4};
    Word previous = {"PREVIOUS", 8};
    Word create = {"CREATE", 6};
    Word add = {"ADD", 3};
    Word delete = {"DELETE", 6};
    Word album = {"ALBUM", 5};

    boolean run = true;
    boolean welcome = true;
    boolean sesi = false;

    while (run)
    {
        printf(">> ");
        IgnoreBlanks();
        IgnoreNewline();
        STARTWORDINPUT();
        Word command = currentWord;
        if (cmp_word(command, start))
        {
            if (welcome)
            {
                welcome = false;
                sesi = true;
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (cmp_word(command, load))
        {
            if (welcome)
            {
                split_word(command);
                welcome = false;
                sesi = true;
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (cmp_word(command, list))
        {
            if (sesi)
            {
                split_word(command);
                if (cmp_word(command, defaults))
                {

                }
                else if (cmp_word(command, playlist))
                {

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
        else if (cmp_word(command, play))
        {
            if (sesi)
            {
                split_word(command);
                if (cmp_word(command, song))
                {

                }
                else if (cmp_word(command, playlist))
                {

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
        else if (cmp_word(command, queue))
        {
            if (sesi)
            {
                split_word(command);
                if (cmp_word(command, song))
                {

                }
                else if (cmp_word(command, playlist))
                {

                }
                else if (cmp_word(command, swap))
                {

                }
                else if (cmp_word(command, remove))
                {
                    
                }
                else if (cmp_word(command, clear))
                {

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
        else if (cmp_word(command, song))
        {
            if (sesi)
            {
                split_word(command);
                if (cmp_word(command, next))
                {

                }
                else if (cmp_word(command, previous))
                {

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
        else if (cmp_word(command, playlist))
        {
            if (sesi)
            {
                split_word(command);
                if (cmp_word(command, create))
                {
                
                }
                else if (cmp_word(command, add))
                {

                }
                else if (cmp_word(command, swap))
                {

                }
                else if (cmp_word(command, remove))
                {

                }
                else if (cmp_word(command, delete))
                {

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
        else if (cmp_word(command, status))
        {
            if (sesi)
            {

            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (cmp_word(command, save))
        {
            if (sesi)
            {

            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (cmp_word(command, quit))
        {
            if (sesi)
            {
                welcome = true;
                sesi = false;
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
        else if (cmp_word(command, help))
        {
            if (welcome)
            {

            }
            else
            {
                
            }
        }
        else
        {
            printf("Command tidak diketahui!\n");
        }
    }

    return 0;
}