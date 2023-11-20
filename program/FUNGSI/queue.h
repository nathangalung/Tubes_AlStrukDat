/* file queue.h */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "../ADT/setmap/map.h"
#include "../ADT/setmap/set.h"
#include "../ADT/linkedlist/linier_list.h"
#include "../ADT/queuestack/queue.h"
#include "play.h"

void queueSong(StaticList artist, Map album_artist, Map song_album, User *multi, StaticList *playing, int idx_user);

void queuePlaylist(LinierList playlist);

void queueSwap(Queue *queue, int *a, int *b);

void queueRemove(int *arr);

void queueClear(Queue *queue);

#endif