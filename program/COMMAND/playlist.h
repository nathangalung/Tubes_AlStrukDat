/* File : playlist.h */
/* ADT berisikan fungsi playlist dengan memanfaatkan Dynamic List dan List Linier */

#ifndef __PLAYLIST_H__
#define __PLAYLIST_H__

#include "../ADT/user/user.h"
#include "../ADT/list/static_list.h"
#include "../ADT/setmap/map.h"
#include "../ADT/pcolor/pcolor.h"

void PlaylistCreate (User *multi, int idx_user);
/* Membuat playlist kosong baru */

void PlaylistAddSong (StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user);
/* Menambahkan lagu ke dalam playlist */

void PlaylistAddAlbum (StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user);
/* Menambahkan semua lagu yang ada pada album ke dalam playlist */

void PlaylistSwap(User *multi, int idx_user, Word word);
/* Menukarkan urutan lagu dari playlist */

void PlaylistRemove (User *multi, int idx_user, Word word);
/* Menghapus lagu pada indeks tertentu yang ada pada playlist */

void PlaylistDelete (User *multi, int idx_user);
/* Menghapus playlist yang ada */

#endif