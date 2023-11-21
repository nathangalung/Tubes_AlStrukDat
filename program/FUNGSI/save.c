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
    string[word.Length] = '\0';

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

void writeword(FILE* file, Word word){
    for (int it = 0; it < word.Length; it++){
        fprintf(file,"%c", word.TabWord[it]);}
        fprintf(file,"\n");
}
void writewordnnl(FILE* file, Word word){
    for (int it = 0; it < word.Length; it++){
        fprintf(file,"%c", word.TabWord[it]);}
}
void writewordmark(FILE* file,Word word, StaticList artist, Set album)
{
    int i = 0;
    while (!CompareWord3(word, artist.A[i]))
    {
        i++;
    }
    writewordnnl(file, artist.A[i]);
    fprintf(file," ; ");
    Word temp = SplitWordMark(word);
    int j = 0;
    while (!CompareWord3(temp, album.Elements[j]))
    {
        j++;
    }
    writewordnnl(file,album.Elements[j]);
    fprintf(file," ; ");
    temp = SplitWordMark(temp);
    writewordnnl(file,temp);
    fprintf(file, "\n");}

void Save(Word filename, StaticList artist, Set album, Map album_artist, Map song_album, DynamicList user, StaticList playing, User multi) {
    char namafile[50];
    int jump=0;
    int idxa=0;
    int idxjump=0;
    Word dash ={'-',1};
    WordToString(filename, namafile);
    FILE *file = fopen(namafile, "w");

    fprintf(file, "%d\n", LengthList(artist)); // jml penyanyi

    int j=0;
    for (int i = 0; i < album_artist.Count; i+=jump) {
        fprintf(file, "%d ", jmlkey(album_artist, album_artist.Elements[i].Value)); // jml album
        writeword(file,album_artist.Elements[i].Value);
        idxjump+=jmlkey(album_artist, album_artist.Elements[i].Value);

        while (j<song_album.Count)
        {
            fprintf(file, "%d ", jmlkey(song_album, album.Elements[idxa]));//jml lagu
            writeword(file, song_album.Elements[j].Value);//menulis nama album
            for (int idx1 = 0; idx1 <  jmlkey(song_album, album.Elements[idxa]); idx1++)
            {
                writeword(file, song_album.Elements[j+idx1].Key);//menulis song
            }
            j+=jmlkey(song_album, album.Elements[idxa]);
            idxa++;
            if (idxa>=idxjump)
            {
                break;
            }
        }
        jump+=jmlkey(album_artist, album_artist.Elements[i].Value);}
    fprintf(file,"%d\n", user.Neff);
    for (int i = 0; i < user.Neff; i++)
    {
        writeword(file, user.A[i]);
    }
    for(int idxuser=0;idxuser<user.Neff;idxuser++){
    if (!CompareWord1(playing.A[idxuser],StringToWord(MarkStatic))){
    writeword(file, playing.A[idxuser]);}//now playing

    fprintf(file,"%d\n", LengthQueue(multi.Elements[idxuser].Queue));//jml queue
    for (int i = 0; i < LengthQueue(multi.Elements[idxuser].Queue); i++){
        writeword(file, multi.Elements[idxuser].Queue.Buffer[i]);}//isi queue

    if ((multi.Elements[idxuser].History.TOP)!=-1)
{    fprintf(file, "%d\n", multi.Elements[idxuser].History.TOP+1);//jml riwayat
    for (int it = multi.Elements[idxuser].History.TOP; it >= 0; it--)
    {
        writeword(file, multi.Elements[idxuser].History.T[it]);
    }
    fprintf(file, "%d\n", multi.Elements[idxuser].Playlist.Neff);
    for (int ip = 0; ip < multi.Elements[idxuser].Playlist.Neff; ip++)
    {
        fprintf(file, "%d ",NbElmt(multi.Elements[idxuser].PlaylistSong[ip].Song));
        writeword(file, multi.Elements[idxuser].Playlist.A[ip]);
        address s=First(multi.Elements[idxuser].PlaylistSong[ip].Song);
        for (int is = 0; is < NbElmt(multi.Elements[idxuser].PlaylistSong[ip].Song); is++)
        {
            writeword(file, s->info);
            s=Next(s);
        }
        
    }
    
    fclose(file);}
}}