/* file queue.h */

#ifndef QUEUE_H
#define QUEUE_H

#include "../ADT/setmap/map.h"
#include "../ADT/setmap/set.h"
#include "../ADT/user/user.h"
#include "../ADT/pcolor/pcolor.h"

void QueueSong(StaticList artist, Map album_artist, Map song_album, User *multi, int idx_user);
/* Memasukkan lagu yang dipilih ke dalam Queue */

void QueuePlaylist(User *multi, int idx_user);
/* Memasukkan semua lagu dari playlist yang dipilih ke dalam Queue */

void QueueSwap(User *multi, Word word, int idx_user);
/* Menukarkan urutan dua lagu pada queue */

void QueueRemove(User *multi, Word word, int idx_user);
/* Menhapus lagu dengan indeks yang dipilih dari queue */

void QueueClear(User *multi, int idx_user);
/* Mengosongkan queue */

#endif