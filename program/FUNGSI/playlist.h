/* File : playlist.h */
/* ADT berisikan fungsi playlist dengan memanfaatkan Dynamic List dan List Linier */

#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include "../ADT/user/user.h"
#include "../ADT/list/static_list.h"
#include "../ADT/setmap/map.h"
#include "../ADT/pcolor/pcolor.h"

void PlaylistCreate (User *multi, int idx_user);

void PlaylistAddSong (StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user);

void PlaylistAddAlbum (StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user);

void PlaylistSwap(User *multi, int idx_user, Word word);

void PlaylistRemove (User *multi, int idx_user, Word word);

void PlaylistDelete (User *multi, int idx_user);

#endif