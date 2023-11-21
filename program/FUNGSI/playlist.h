/* File : playlist.h */
/* ADT berisikan fungsi playlist dengan memanfaatkan Dynamic List dan List Linier */

#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include "../ADT/user/user.h"
#include "../ADT/list/static_list.h"
#include "../ADT/setmap/map.h"

void CreatePlaylist (User *multi, int idx_user);

void AddSongPlaylist (StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user);

void AddAlbumPlaylist (StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user);

void SwapPlaylist (User *multi, int idx_user, Word word);

void RemovePlaylist (User *multi, int idx_user, Word word);

void DeletePlaylist (User *multi, int idx_user);

#endif