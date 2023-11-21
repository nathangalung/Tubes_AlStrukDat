#ifndef __START_H__
#define __START_H__

#include "../ADT/list/static_list.h"
#include "../ADT/setmap/set.h"
#include "../ADT/setmap/map.h"
#include "../ADT/user/user.h"

void Start(StaticList *count, StaticList *artist, Set *album, Map *album_artist, Map *song_album, DynamicList *user, User *multi);

#endif