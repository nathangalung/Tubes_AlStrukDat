#ifndef __LOAD_H__
#define __LOAD_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/list/static_list.h"
#include "../ADT/list/dynamic_list.h"
#include "../ADT/setmap/set.h"
#include "../ADT/setmap/map.h"
#include "../ADT/queuestack/queue.h"
#include "../ADT/queuestack/stack.h"

void load(Word filename, StaticList *count, StaticList *artist, Set *album, Map *album_artist, Map *song_album, DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist);

#endif