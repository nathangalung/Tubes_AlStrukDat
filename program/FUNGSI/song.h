#ifndef SONG_H
#define SONG_H

#include "../ADT/setmap/map.h"
#include "../ADT/list/static_list.h"
#include "../ADT/user/user.h"
#include "../ADT/machine/wordmachine.h"

void SongNext(User *multi, StaticList artist, DynamicList *playing, int idx_user);

void SongPrevious(User *multi, StaticList artist, DynamicList *playing, int idx_user);

#endif