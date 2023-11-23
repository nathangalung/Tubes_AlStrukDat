#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <stdio.h>

#include "../ADT/pcolor/pcolor.h"

#define MAX_LEN 5000

void DelayLoad(int seconds);

void Image(FILE *filename);

void WelcomeImage();

void StartImage();

void LoadImage();

void QuitImage();

#endif