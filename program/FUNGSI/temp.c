#include <stdio.h>
#include <stdlib.h>
#include "save.h"

int length(char *s){
    int ctr=0;
    while (s[ctr]!='\0'){
        ctr++;
    }
    return ctr;
}
void WordToString(Word word, char *string) {
    // Memastikan string berakhir dengan karakter null
    string[word.Length] = '\0';

    // Menyalin karakter-karakter dari TabWord ke string
    for (int i = 0; i < word.Length; i++) {
        string[i] = word.TabWord[i];
    }
}

int jmlkey(Map map, Word value){
    int count = 0;
    
    for (int i = 0; i < map.Count; i++) {
        if (CompareWord1(map.Elements[i].Value,value)) {
            count++;
        }
    }
    
    return count;
}

void Save(Word filename, StaticList artist, Set album, Map album_artist, Map song_album, DynamicList user, StaticList playing, User multi, PlaylistSong playlist_song) {
    char namafile[50]; // Ganti sesuai kebutuhan
    int jump=0;
    WordToString(filename, namafile);
    FILE *file = fopen(namafile, "w");

    if (file == NULL) {
        printf("Gagal membuat file %s\n", namafile);
        return;
    }

    fprintf(file, "%d\n", LengthList(artist)); // jml penyanyi

    for (int i = 0; i < album_artist.Count; i+=jump) {
        fprintf(file, "%d ", jmlkey(album_artist, album_artist.Elements[i].Value)); // jml album
        for (int it = 0; it < album_artist.Elements[i].Value.Length; it++){//nama penyanyi
        fprintf(file,"%c", album_artist.Elements[i].Value.TabWord[it]);}
        fprintf(file,"\n");
        for (int j = 0; j < jmlkey(album_artist, album_artist.Elements[i].Value); j++) {
            fprintf(file, "%d ", jmlkey(song_album, song_album.Elements[j].Value)); // jml lagu, nama album
            for (int it = 0; it < song_album.Elements[j].Value.Length; it++){//nama penyanyi
                fprintf(file,"%c", song_album.Elements[j].Value.TabWord[it]);}
                fprintf(file,"\n");
        }
        jump+=jmlkey(album_artist, album_artist.Elements[i].Value);}
    //         for (int k = 0; k < jmlkey(song_album, song_album.Elements[j].Value); k++) {
    //             fprintf(file, "%s", song_album.Elements[k].Key); // judul lagu
    //         }
    //     }
    // }

    fclose(file);
}