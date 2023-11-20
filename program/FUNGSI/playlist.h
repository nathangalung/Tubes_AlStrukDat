/* File : playlist.h */
/* ADT berisikan fungsi playlist dengan memanfaatkan Dynamic List dan List Linier */

#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include "../ADT/user/user.h"
#include "../ADT/list/static_list.h"
#include "../ADT/setmap/map.h"
#include "../ADT/linkedlist/linier_list.h"
#include "../ADT/machine/wordmachine.h"

void CreatePlaylist (User *multi, int idx_user);

void AddSongPlaylist (StaticList *artist, Map *album_artist, Map *song_album, DynamicList *playlist, LinierList *playlist_song);

void AddAlbumPlaylist (StaticList *artist, Map *album_artist, Map *song_album, DynamicList *playlist, LinierList *playlist_song);

#endif