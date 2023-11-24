/* file play.h */

#ifndef PLAY_H
#define PLAY_H

#include <stdio.h>
#include "../ADT/queuestack/queue.h"
#include "../ADT/list/static_list.h"
#include "../ADT/list/dynamic_list.h"
#include "../ADT/machine/wordmachine.h"
#include "../ADT/queuestack/queue.h"
#include "../ADT/setmap/map.h"
#include "../ADT/user/user.h"
#include "../ADT/pcolor/pcolor.h"

void PlaySong(StaticList artist, Map album_artist, Map song_album, User *multi, DynamicList *playing, int idx_user);
/* Memainkan lagu yang dipilih */
/* Lagu terpilih menjadi Now Playing */
/* Queue dan History kosong */

void PlayPlaylist(User *multi, DynamicList *playing, int idx_user);
/* Memainkan playlist yang dipilih */
/* Now Playing berisi lagu pertama dari playlist yang dipilih */
/* Queue lagu berisi lagu kedua hingga lagu terakhir dari playlist yang dipilih */
/* History lagu berisi Queue namun dalam posisi yang terbalik */

#endif