/* File : list.h */
/* ADT berisikan fungsi list dengan memanfaatkan Static List */

#ifndef __LIST_H__
#define __LIST_H__

#include "../ADT/list/static_list.h"
#include "../ADT/setmap/map.h"
#include "../ADT/machine/wordmachine.h"
#include "../ADT/list/dynamic_list.h"

void ListDefault (StaticList artist, Map album_artist, Map song_album);

void ListPlaylist (DynamicList *playlist);

#endif