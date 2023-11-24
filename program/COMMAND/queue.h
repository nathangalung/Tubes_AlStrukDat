/* file queue.h */

#ifndef QUEUE_H
#define QUEUE_H

#include "../ADT/setmap/map.h"
#include "../ADT/setmap/set.h"
#include "../ADT/user/user.h"
#include "../ADT/pcolor/pcolor.h"

void QueueSong(StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user);

void QueuePlaylist(User *multi, int idx_user);

void QueueSwap(User *multi, Word word, int idx_user);

void QueueRemove(User *multi, Word word, int idx_user);

void QueueClear(User *multi, int idx_user);

#endif