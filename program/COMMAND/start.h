#ifndef __START_H__
#define __START_H__

#include "../ADT/list/static_list.h"
#include "../ADT/setmap/set.h"
#include "../ADT/setmap/map.h"
#include "../ADT/user/user.h"
#include "../ADT/pcolor/pcolor.h"

void Start(StaticList *artist, Set *album, Map *album_artist, Map *song_album, DynamicList *user, DynamicList *playing, User *multi);
/* Memuat file konfigurasi default untuk dimasukkan ke dalam seluruh struktur data */
/*  I.S. Data struktur semua masih belum dibuat dan kosong
    F.S Data struktur semua sudah dibuat dan terisi sesuai dengan data yang dibaca */

#endif