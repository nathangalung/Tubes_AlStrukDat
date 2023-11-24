/* File : list.h */
/* ADT berisikan fungsi list dengan memanfaatkan Static List */

#ifndef __LIST_H__
#define __LIST_H__

#include "../ADT/list/static_list.h"
#include "../ADT/setmap/map.h"
#include "../ADT/machine/wordmachine.h"
#include "../ADT/user/user.h"
#include "../ADT/pcolor/pcolor.h"

void ListDefault (StaticList artist, Map album_artist, Map song_album);

void ListPlaylist (User multi, int idx_user);

#endif