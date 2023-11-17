/* file queue.h */

#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include "../ADT/setmap/map.h"
#include "../ADT/setmap/set.h"
#include "../ADT/linkedlist/linier_list.h"
#include "../ADT/queuestack/queue.h"

void queueSong(Map album_artist, Set album, Map song_album);

void queuePlaylist(LinierList playlist);

void queueSwap(Queue *queue, int *a, int *b);

void queueRemove(int *arr);

void queueClear(Queue *queue);

#endif