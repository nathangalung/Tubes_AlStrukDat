#ifndef SONG_H
#define SONG_H

#include "../ADT/setmap/map.h"
#include "../ADT/list/static_list.h"
#include "../ADT/user/user.h"
#include "../ADT/machine/wordmachine.h"
#include "../ADT/pcolor/pcolor.h"

void SongNext(User *multi, StaticList artist, DynamicList *playing, int idx_user);
/* 
    I.S Memainkan sebuah lagu
    F.S Lagu yang dimainkan berubah ke lagu selanjutnya yang terdapat pada queue. Aplikasi memutar ulang lagu yang sedang dimainkan jika tidak ada queue.
*/

void SongPrevious(User *multi, StaticList artist, DynamicList *playing, int idx_user);
/*
    I.S Memainkan sebuah lagu
    F.S Lagu yang dimainkan berubah ke lagu sebelumnya yang ada di riwayat lagu. Aplikasi memutar ulang lagu yang sedang dimainkan jika tidak ada riwayat lagu.
*/
#endif