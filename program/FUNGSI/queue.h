/* file queue.h */

#ifndef PLAY_H
#define PLAY_H

#include <stdio.h>
#include "../ADT/setmap/map.h"
#include "../ADT/setmap/set.h"
#include "../ADT/linkedlist/linier_list.h"
#include "../ADT/queuestack/queue.h"

int queueSong(Map album_artist, Set album, Map song_album);

int queuePlaylist(LinierList playlist);

int queueSwap(int *a, int *b);

int queueRemove(int *arr);

int queueClear();

#endif