/* file play.h */

#ifndef PLAY_H
#define PLAY_H

#include <stdio.h>
#include "../ADT/queuestack/queue.h"
#include "../ADT/list/array.h"
#include "../ADT/machine/wordmachine.h"
#include "../ADT/queuestack/stack.h"
#include "../ADT/setmap/map.h"
#include "../ADT/setmap/set.h"
#include "../ADT/linkedlist/listlinier.h"

int playSong(Map album_artist, Set album, Map song_album, Word song, Word penyanyi);

int playPlaylist(LinkedList playlist);

#endif