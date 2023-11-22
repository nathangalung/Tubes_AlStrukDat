#include <stdio.h>
#include <stdlib.h>
#include "save.h"

int length(char *s)
{
    int ctr = 0;

    while (s[ctr]!='\0')
    {
        ctr++;
    }
    return ctr;
}
void WordToString(Word word, char *string)
{
    string[word.Length] = '\0';

    for (int i = 0; i < word.Length; i++)
    {
        string[i] = word.TabWord[i];
    }
}

int jmlkey(Map map, Word value)
{
    int count = 0;
    
    for (int i = 0; i < map.Count; i++)
    {
        if (CompareWord(map.Elements[i].Value,value))
        {
            count++;
        }
    }
    
    return count;
}

void writeword(FILE* File, Word word)
{
    for (int it = 0; it < word.Length; it++)
    {
        fprintf(File,"%c", word.TabWord[it]);
    }
    fprintf(File,"\n");
}

void writewordnnl(FILE* File, Word word)
{
    for (int it = 0; it < word.Length; it++)
    {
        fprintf(File,"%c", word.TabWord[it]);
    }
}

void Save(Word filename, StaticList artist, Set album, Map album_artist, Map song_album, DynamicList user, StaticList playing, User multi)
{
    char namafile[50];
    int jump = 0;
    int idxa = 0;
    int idxjump = 0;
    
    WordToString(filename, namafile);
    FILE *File = fopen(namafile, "w");

    fprintf(File, "%d\n", LengthList(artist)); // jml penyanyi

    int j=0;
    for (int i = 0; i < album_artist.Count; i+=jump)
    {
        fprintf(File, "%d ", jmlkey(album_artist, album_artist.Elements[i].Value)); // jml album
        writeword(File,album_artist.Elements[i].Value);
        idxjump+=jmlkey(album_artist, album_artist.Elements[i].Value);

        while (j<song_album.Count)
        {
            fprintf(File, "%d ", jmlkey(song_album, album.Elements[idxa]));//jml lagu
            writeword(File, song_album.Elements[j].Value);//menulis nama album

            for (int idx1 = 0; idx1 <  jmlkey(song_album, album.Elements[idxa]); idx1++)
            {
                writeword(File, song_album.Elements[j+idx1].Key);//menulis song
            }

            j+=jmlkey(song_album, album.Elements[idxa]);
            idxa++;

            if (idxa>=idxjump)
            {
                break;
            }
        }

        jump+=jmlkey(album_artist, album_artist.Elements[i].Value);
    }

    fprintf(File,"%d\n", user.Neff);//jml user

    for (int i = 0; i < user.Neff; i++)
    {
        writeword(File, user.A[i]);//nama user
    }
//========================================================================

    for(int idxuser=0;idxuser<user.Neff;idxuser++){
    writeword(File, playing.A[idxuser]);//now playing

    fprintf(File,"%d\n", LengthQueue(multi.Elements[idxuser].Queue));//jml queue
    for (int i = 0; i < LengthQueue(multi.Elements[idxuser].Queue); i++){
        writeword(File, multi.Elements[idxuser].Queue.Buffer[i]);}//isi queue

    fprintf(File, "%d\n", multi.Elements[idxuser].History.TOP+1);//jml riwayat
    for (int it = multi.Elements[idxuser].History.TOP; it >= 0; it--){
        writeword(File, multi.Elements[idxuser].History.T[it]);//riwayat
    }

    if(multi.Elements[idxuser].Playlist.Neff==0 && idxuser==user.Neff-1){
        fprintf(File, "%d", multi.Elements[idxuser].Playlist.Neff);}//jml playlist
    else{
        fprintf(File, "%d\n", multi.Elements[idxuser].Playlist.Neff);}//jml playlist

    for (int ip = 0; ip < multi.Elements[idxuser].Playlist.Neff; ip++)
    {
        fprintf(File, "%d ",NbElmt(multi.Elements[idxuser].PlaylistSong[ip].Song));//jml lagu
        if(idxuser==user.Neff-1 && ip==multi.Elements[idxuser].Playlist.Neff-1){
            writewordnnl(File, multi.Elements[idxuser].Playlist.A[ip]);}
        else{
            writeword(File, multi.Elements[idxuser].Playlist.A[ip]);}//nama playlist
        address s=First(multi.Elements[idxuser].PlaylistSong[ip].Song);
        for (int is = 0; is < NbElmt(multi.Elements[idxuser].PlaylistSong[ip].Song); is++)
        {
            if(idxuser==user.Neff-1 && ip==multi.Elements[idxuser].Playlist.Neff-1 && is==NbElmt(multi.Elements[idxuser].PlaylistSong[ip].Song)-1){
                writewordnnl(File, s->info);
            }
            writeword(File, s->info);//nama lagu
            s=Next(s);
        }
        
    }}
    
    fclose(File);
}