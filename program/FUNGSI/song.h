#ifndef SONG_H
#define SONG_H

#include "../ADT/setmap/map.h"
#include "../ADT/list/static_list.h"
#include "../ADT/user/user.h"
#include "../ADT/machine/wordmachine.h"

void songNext(User *multi, StaticList artist, StaticList *playing, int idx_user);

void songPrevious(User *multi, StaticList artist, StaticList *playing, int idx_user);

#endif