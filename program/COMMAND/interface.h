#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <stdio.h>

#include "../ADT/pcolor/pcolor.h"

#define MAX_LEN 5000

void DelayLoad(int seconds);
/*Memberikan jeda dalam penampilan gambar*/

void Image(FILE *filename);
/*Menampilkan gambar dengan warna kuning*/

void WelcomeImage();
/*Menampilkan animasi untuk welcome*/

void StartImage();
/*Menampilkan animasi untuk fungsi start*/

void LoadImage();
/*Menampilkan animasi untuk fungsi load*/

void QuitImage();
/*Menampilkan animasi untuk fungsi quit*/

#endif