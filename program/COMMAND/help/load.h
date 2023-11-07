#ifndef __LOAD_H__
#define __LOAD_H__

#include "../ADT/queue/queue.h"
#include "../ADT/list/static_list.h"
#include "../ADT/machine/wordmachine.h"

void load(char *filename, Set album, Map album_artist, Map song_album, List user, Queue *queue, Stack *history, DynamicList *playlist);

#endif