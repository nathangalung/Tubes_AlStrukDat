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
    StaticList artist, playing;
    Set album;
    Map album_artist, song_album;
    DynamicList user;
    User multi;
    Word dir = {"config/", 7};
    
    boolean run = true, menu = false, sesi = false;
    int idx_user = -1;

    Welcome();

    while (run)
    {
        printf("%s\n>> ", GREEN);
        StartWordMark();
        IgnoreBlanks();
        IgnoreNewlines();
        printf("%s\n", WHITE);
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
                printf("%s\nCommand tidak bisa dieksekusi!\n", RED);
            }
        }
        else if (CompareStringWord(SplitWordLeftBlank(command), "LOAD"))
        {
            if (!menu)
            {
                command = SplitWordBlank(command);
                Word filename = ConcatWord(dir, command);
                DisplayWord(filename);
                printf("\n");
                Load(filename, &artist, &album, &album_artist, &song_album, &user, &playing, &multi, &menu);
            }
            else
            {
                printf("%s\nCommand tidak bisa dieksekusi!\n", RED);
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
                printf("%s\nCommand tidak bisa dieksekusi!\n", RED);
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
                printf("%s\nCommand tidak bisa dieksekusi!\n", RED);
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
                printf("%s\nCommand tidak bisa dieksekusi!\n", RED);
            }
        }
        else if (CompareStringWord(SplitWordLeftBlank(command), "LIST"))
        {
            if (sesi)
            {
                command = SplitWordBlank(command);
                if (CompareStringWord(command, "DEFAULT"))
                {
                    ListDefault(artist, album_artist, song_album);
                }
                else if (CompareStringWord(command, "PLAYLIST"))
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
        else if (CompareStringWord(SplitWordLeftBlank(command), "PLAY"))
        {
            if (sesi)
            {
                command = SplitWordBlank(command);
                if (CompareStringWord(command, "SONG"))
                {
                    playSong(artist, album_artist, song_album, &multi, &playing, idx_user);
                }
                else if (CompareStringWord(command, "PLAYLIST"))
                {
                    playPlaylist(&multi, &playing, idx_user);
                }
                else
                {
                    printf("%s\nCommand tidak diketahui!\n", RED);
                }
            }
            else
            {
                printf("%s\nCommand tidak bisa dieksekusi!\n", RED);
            }
        }
        else if (CompareStringWord(SplitWordLeftBlank(command), "QUEUE"))
        {
            if (sesi)
            {
                command = SplitWordBlank(command);
                if (CompareStringWord(command, "SONG"))
                {
                    queueSong(artist, album_artist, song_album, &multi, idx_user);
                }
                else if (CompareStringWord(command, "PLAYLIST"))
                {
                    queuePlaylist(&multi, idx_user);
                }
                else if (CompareStringWord(SplitWordLeftBlank(command), "SWAP"))
                {
                    command = SplitWordBlank(command);
                    queueSwap(&multi, command, idx_user);
                    
                }
                else if (CompareStringWord(SplitWordLeftBlank(command), "REMOVE"))
                {
                    command = SplitWordBlank(command);
                    queueRemove(&multi, command, idx_user);
                }
                else if (CompareStringWord(command, "CLEAR"))
                {
                    queueClear(&multi, idx_user);
                }
                else
                {
                    printf("%s\nCommand tidak diketahui!\n", RED);
                }
            }
            else
            {
                printf("%s\nCommand tidak bisa dieksekusi!\n", RED);
            }
        }
        else if (CompareStringWord(SplitWordLeftBlank(command), "SONG"))
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
                    printf("%s\nCommand tidak diketahui!\n", RED);
                }
            }
            else
            {
                printf("%s\nCommand tidak bisa dieksekusi!\n", RED);
            }
        }
        else if (CompareStringWord(SplitWordLeftBlank(command), "PLAYLIST"))
        {
            if (sesi)
            {
                command = SplitWordBlank(command);
                if (CompareStringWord(command, "CREATE"))
                {
                    CreatePlaylist(&multi, idx_user);
                }
                else if (CompareStringWord(SplitWordLeftBlank(command), "ADD"))
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
                        printf("%sCommand tidak diketahui!\n", RED);
                    }
                }
                else if (CompareStringWord(SplitWordLeftBlank(command), "SWAP"))
                {
                    command = SplitWordBlank(command);
                    SwapPlaylist(&multi, idx_user, command);
                }
                else if (CompareStringWord(SplitWordLeftBlank(command), "REMOVE"))
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
                    printf("%sCommand tidak diketahui!\n", RED);
                }
            }
            else
            {
                printf("Command tidak bisa dieksekusi!\n");
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
                printf("%sCommand tidak bisa dieksekusi!\n", RED);
            }
        }
        else if (CompareStringWord(SplitWordLeftBlank(command), "SAVE"))
        {
            if (menu || sesi)
            {
                command = SplitWordBlank(command);
                Word filename = ConcatWord(dir, command);
                Save(filename, artist, album, album_artist, song_album, user, playing, multi);
                printf("save file berhasil disimpan\n");
            }
            else
            {
                printf("%sCommand tidak bisa dieksekusi!\n", RED);
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
                    Word filename = ConcatWord(StringToWord("config/"), currentWord);
                    Save(filename, artist, album, album_artist, song_album, user, playing, multi);
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
                printf("Command tidak bisa dieksekusi!\n");
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
                printf("%sCommand tidak bisa dieksekusi!\n", RED);
            }
        }
        else
        {
            printf("%sCommand tidak diketahui!\n", RED);
        }
        printf("%s\n=======================================================================================================================\n", YELLOW);
    }
}