#ifndef __ENCHANCE_H__
#define __ENCHANCE_H__

#include "../ADT/list/static_list.h"
#include "../ADT/setmap/set.h"
#include "../ADT/setmap/map.h"
#include "../ADT/user/user.h"

int randint(int n);

void Enhance(StaticList artist, Set album, Map song_album, Map album_artist, User multi, int idx_user);

#endif