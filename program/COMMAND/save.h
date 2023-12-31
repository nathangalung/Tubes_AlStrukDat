#ifndef __SAVE_H__
#define __SAVE_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/list/static_list.h"
#include "../ADT/setmap/set.h"
#include "../ADT/setmap/map.h"
#include "../ADT/user/user.h"
#include "../ADT/pcolor/pcolor.h"

int jmlkey(Map map, Word value);
/* Menghitung jumlah key */

void writeword(FILE* File, Word word);
/* Menuliskan kata */

void writewordnnl(FILE* File, Word word);
/* Menuliskan kata tanpa new line */

void Save(Word command, StaticList artist, Set album, Map album_artist, Map song_album, DynamicList user, DynamicList playing, User multi);
/* Menyimpan file konfigurasi */

#endif