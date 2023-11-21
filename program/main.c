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
#include "FUNGSI/song.h"
#include "FUNGSI/save.h"

int main()
{
    Word load_cmp = {"LOAD", 4};
    Word list_cmp = {"LIST", 4};
    Word play_cmp = {"PLAY", 4};
    Word queue_cmp = {"QUEUE", 5};
    Word song_cmp = {"SONG", 4};
    Word playlist_cmp = {"PLAYLIST", 8};
    Word save_cmp = {"SAVE", 4};
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
        printf("\n>> ");
        StartWordMark();
        IgnoreBlanks();
        IgnoreNewlines();
        Word command = currentWord;

        if (CompareStringWord(command, "START"))
        {
            if (!menu)
            {
                Start(&artist, &album, &album_artist, &song_album, &user, &multi);
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
                    Load(filename, file, &artist, &album, &album_artist, &song_album, &user, &playing, &multi);
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
        else if (CompareStringWord(command, "SIGN UP"))
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
        else if (CompareStringWord(command, "LOGIN"))
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
        else if (CompareStringWord(command, "LOGOUT"))
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
                if (CompareStringWord(command, "NEXT"))
                {
                    songNext(&multi, artist, &playing, idx_user);
                }
                else if (CompareStringWord(command, "PREVIOUS"))
                {
                    songPrevious(&multi, artist, &playing, idx_user);
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
                if (CompareStringWord(command, "CREATE"))
                {
                    CreatePlaylist(&multi, idx_user);
                }
                else if (CompareWord2(command, add_cmp))
                {
                    command = SplitWordBlank(command);
                    if (CompareStringWord(command, "SONG"))
                    {
                        AddSongPlaylist(artist, album_artist, song_album, &multi, idx_user);
                    }
                    else if (CompareStringWord(command, "ALBUM"))
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
                    RemovePlaylist(&multi, idx_user, command);
                }
                else if (CompareStringWord(command, "DELETE"))
                {
                    DeletePlaylist(&multi, idx_user);
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
        else if (CompareStringWord(command, "STATUS"))
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
                Word filename = ConcatWord(dir, command);
                Save(filename, artist, album, album_artist, song_album, user, playing, multi, &file);
                printf("save file berhasil disimpan\n");
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareStringWord(command, "QUIT"))
        {
            if (sesi)
            {
                sesi = false;

                printf("keluar dari sesi\n");
            }
            else if (menu)
            {
                menu = false;
                printf("Apakah kamu ingin menyimpan data sesi sekarang? (Y/N) : ");
                StartWordMark();
                if (CompareStringWord(currentWord,"Y")){
                    printf("ketik \"<nama_file>.txt\" : ");
                    StartWordMark();
                    Word filename = ConcatWord(dir, currentWord);
                    Save(filename, artist, album, album_artist, song_album, user, playing, multi, &file);
                    printf("File berhasil disimpan\n");
                }
                printf("keluar dari menu\n");
            }
            else if (run)
            {
                run = false;
                printf("keluar dari program\n");
            }
            else
            {
                printf("\nCommand tidak bisa dieksekusi!\n");
            }
        }
        else if (CompareStringWord(command, "HELP"))
        {
            help(sesi, menu);
        }
        else if (CompareStringWord(command, "ENHANCE"))
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
        printf("\n=======================================================================================================================\n");
    }
}