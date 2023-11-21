#ifndef __LOAD_H__
#define __LOAD_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/list/static_list.h"
#include "../ADT/setmap/set.h"
#include "../ADT/setmap/map.h"
#include "../ADT/user/user.h"

void Load(Word filename, DynamicList file, StaticList *artist, Set *album, Map *album_artist, Map *song_album, DynamicList *user, StaticList *playing, User *multi, boolean *menu);

#endif