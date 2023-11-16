/* Driver Testing untuk file playlist.c */

#include "../FUNGSI/playlist.h"

int main(){
    DynamicList playlist;
    CreateEmptyDynamic(&playlist);
    CreatePlaylist(&playlist);
    return 0;
}