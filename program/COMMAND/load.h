#ifndef __LOAD_H__
#define __LOAD_H__

#include "../ADT/machine/wordmachine.h"
#include "../ADT/list/static_list.h"
#include "../ADT/setmap/set.h"
#include "../ADT/setmap/map.h"
#include "../ADT/user/user.h"
#include "../ADT/pcolor/pcolor.h"

void Load(Word filename, StaticList *artist, Set *album, Map *album_artist, Map *song_album, DynamicList *user, DynamicList *playing, User *multi, boolean *menu);
/* Memuat save file yang sudah pernah dibuat untuk dimasukkan ke dalam seluruh struktur data */
/*  I.S. Data struktur semua masih belum dibuat dan kosong
    F.S Data struktur semua sudah dibuat dan terisi sesuai dengan data yang dibaca */

#endif