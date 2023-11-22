#ifndef __SAVE_H__
#define __SAVE_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/list/static_list.h"
#include "../ADT/setmap/set.h"
#include "../ADT/setmap/map.h"
#include "../ADT/user/user.h"

int jmlkey(Map map, Word value);

void writeword(FILE* File, Word word);

void writewordnnl(FILE* File, Word word);

void Save(Word filename, StaticList artist, Set album, Map album_artist, Map song_album, DynamicList user, DynamicList playing, User multi);

#endif