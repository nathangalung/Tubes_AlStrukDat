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
#include "FUNGSI/queue.h"
#include "FUNGSI/multi.h"
#include "FUNGSI/enhance.h"
#include "FUNGSI/queue.h"
#include "FUNGSI/status.h"
#include "FUNGSI/interface.h"

int main()
{
    Word start_cmp = {"START", 5};
    Word load_cmp = {"LOAD", 4};
    Word login_cmp = {"LOGIN", 5};
    Word logout_cmp = {"LOGOUT", 6};
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
    Word enhance_cmp = {"ENHANCE", 7};
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
    Word save_file = {"config/save.txt", 15};
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
    Queue queue;
    StaticList playing;
    User multi;

    CreateEmptyDynamic(&file);
    CreateEmptyStatic(&count);
    CreateEmptyStatic(&artist);
    CreateEmptyMap(&album_artist);
    CreateEmptyMap(&song_album);
    CreateEmptySet(&album);
    CreateEmptyDynamic(&user);
    CreateEmptyStatic(&playing);
    InsertLastDynamic(&file, test_file);
    InsertLastDynamic(&file, save_file);
    CreateEmptyUser(&multi);
    
    boolean run = true, menu = false, sesi = false;
    int idx_user = -1;

    Welcome();

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
                Start(&count, &artist, &album, &album_artist, &song_album, &user, &multi);
                menu = true;
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, load_cmp))
        {
            if (!menu)
            {
                command = SplitWordBlank(command);
                Word filename = ConcatWord(dir, command);
                if (CheckDir(&file, filename))
                {
                    Load(filename, file, &count, &artist, &album, &album_artist, &song_album, &user, &playing, &multi);
                    printf("\nSave file berhasil dibaca. WayangWave berhasil dijalankan.\n");
                    menu = true;
                }
                else
                {
                    printf("\nSave file tidak ditemukan. WayangWave gagal dijalankan.\n");
                }
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, signup_cmp))
        {
            if (menu && !sesi)
            {
                SignUp(&user);
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, login_cmp))
        {
            if (menu && !sesi)
            {
                idx_user = Login(&user, &multi, idx_user);
                sesi = true;
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, logout_cmp))
        {
            if (sesi)
            {
                idx_user = Logout(&multi, idx_user);
                sesi = false;
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, list_cmp))
        {
            if (sesi)
            {
                command = SplitWordBlank(command);
                if (CompareWord1(command, default_cmp))
                {
                    ListDefault(artist, album_artist, song_album);
                }
                else if (CompareWord1(command, playlist_cmp))
                {
                    ListPlaylist(multi, idx_user);
                }
                else
                {
                    printf("\nCommand tidak diketahui!\n");
                }
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, play_cmp))
        {
            if (sesi)
            {
                command = SplitWordBlank(command);
                if (CompareWord1(command, song_cmp))
                {
                    playSong(artist, album_artist, song_album, &multi, &playing, idx_user);
                }
                else if (CompareWord1(command, playlist_cmp))
                {
                    playPlaylist(&multi, &playing, idx_user);
                }
                else
                {
                    printf("\nCommand tidak diketahui!\n");
                }
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, queue_cmp))
        {
            if (sesi)
            {
                command = SplitWordBlank(command);
                if (CompareWord1(command, song_cmp))
                {
                    queueSong(artist, album_artist, song_album, &multi, idx_user);
                }
                else if (CompareWord1(command, playlist_cmp))
                {
                    queuePlaylist(&multi, idx_user);
                }
                else if (CompareWord2(command, swap_cmp))
                {
                    command = SplitWordBlank(command);
                    queueSwap(&multi, command, idx_user);
                    
                }
                else if (CompareWord2(command, remove_cmp))
                {
                    command = SplitWordBlank(command);
                    queueRemove(&multi, command, idx_user);
                }
                else if (CompareWord1(command, clear_cmp))
                {
                    queueClear(&multi, idx_user);
                }
                else
                {
                    printf("\nCommand tidak diketahui!\n");
                }
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, song_cmp))
        {
            if (sesi)
            {
                command = SplitWordBlank(command);
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
                    printf("\nCommand tidak diketahui!\n");
                }
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, playlist_cmp))
        {
            if (sesi)
            {
                command = SplitWordBlank(command);
                if (CompareWord1(command, create_cmp))
                {
                    CreatePlaylist(&multi, idx_user);
                }
                else if (CompareWord2(command, add_cmp))
                {
                    command = SplitWordBlank(command);
                    if (CompareWord1(command, song_cmp))
                    {
                        AddSongPlaylist(artist, album_artist, song_album, &multi, idx_user);
                    }
                    else if (CompareWord1(command, album_cmp))
                    {
                        AddAlbumPlaylist(artist, album_artist, song_album, &multi, idx_user);
                    }
                    else
                    {
                        printf("\nCommand tidak diketahui!\n");
                    }
                }
                else if (CompareWord2(command, swap_cmp))
                {
                    command = SplitWordBlank(command);
                    SwapPlaylist(&multi, idx_user, command);
                }
                else if (CompareWord2(command, remove_cmp))
                {
                    command = SplitWordBlank(command);
                    printf("playlist remove\n");
                }
                else if (CompareWord1(command, delete_cmp))
                {
                    printf("playlist delete\n");
                }
                else
                {
                    printf("\nCommand tidak diketahui!\n");
                }
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, status_cmp))
        {
            if (sesi)
            {
                status(multi, artist, album, playing, idx_user);
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord2(command, save_cmp))
        {
            if (sesi)
            {
                command = SplitWordBlank(command);
                printf("save\n");
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, quit_cmp))
        {
            if (sesi)
            {
                sesi = false;

                printf("quit sesi\n");
            }
            else if (menu)
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
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareWord1(command, help_cmp))
        {
            help(sesi, menu);
        }
        else if (CompareWord1(command, enhance_cmp))
        {
            if (sesi)
            {
                Enhance(artist, album, song_album, album_artist, multi, idx_user);
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else
        {
            printf("\nCommand tidak diketahui!\n");
        }
        printf("\n");
    }
}