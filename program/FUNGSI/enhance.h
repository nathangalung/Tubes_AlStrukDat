#ifndef __ENCHANCE_H__
#define __ENCHANCE_H__

#include "../ADT/setmap/map.h"
#include "../ADT/user/user.h"
#include "../ADT/playlist_song/playlist_song.h"

int randint(int n);

void Enhance(Map song_album, User multi, PlaylistSong *playlist_song, int idx_user);

#endif