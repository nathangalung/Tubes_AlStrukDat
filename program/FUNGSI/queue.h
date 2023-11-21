/* file queue.h */

#ifndef QUEUE_H
#define QUEUE_H

#include "../ADT/setmap/map.h"
#include "../ADT/setmap/set.h"
#include "../ADT/user/user.h"

void queueSong(StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user);

void queuePlaylist(User *multi, int idx_user);

void queueSwap(User *multi, Word word, int idx_user);

void queueRemove(User *multi, Word word, int idx_user);

void queueClear(User *multi, int idx_user);

#endif