#ifndef __SAVE_H__
#define __SAVE_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/list/static_list.h"
#include "../ADT/setmap/set.h"
#include "../ADT/setmap/map.h"
#include "../ADT/user/user.h"
#include "../ADT/playlist_song/playlist_song.h"

void Save(Word filename, StaticList artist, Set album, Map album_artist, Map song_album, DynamicList user, StaticList playing, User multi);

#endif