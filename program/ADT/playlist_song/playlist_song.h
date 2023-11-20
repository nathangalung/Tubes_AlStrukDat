#ifndef __PLAYLIST_SONG_H__
#define __PLAYLIST_SONG_H__

#include "../linkedlist/linier_list.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define NilPlaylistSong 0
#define MaxElPlaylistSong 50
#define UndefinedPlaylistSong NULL


typedef struct {
	LinierList Song;
} Info;

typedef struct {
	Info Playlist[MaxElPlaylistSong];
	int Count;
} PlaylistSong;


void CreateEmptyPlaylistSong(PlaylistSong *playlist_song);

#endif