#include <stdio.h>
#include <stdlib.h>
#include "save.h"
// ========================================================================================= JUMLAH KEY ======================================================================================================== //
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
// ========================================================================================= WRITE WORD ======================================================================================================== //
void writeword(FILE* File, Word word)
{
    for (int it = 0; it < word.Length; it++)
    {
        fprintf(File,"%c", word.TabWord[it]);
    }
    fprintf(File,"\n");
}
// ========================================================================================= WRITE WORD NO NEWLINE ======================================================================================================== //
void writewordnnl(FILE* File, Word word)
{
    for (int it = 0; it < word.Length; it++)
    {
        fprintf(File,"%c", word.TabWord[it]);
    }
}
// ========================================================================================= SAVE ======================================================================================================== //
void Save(Word command, StaticList artist, Set album, Map album_artist, Map song_album, DynamicList user, DynamicList playing, User multi)
{
    char namafile[50];
    int jump = 0, idxa = 0, idxjump = 0, count = 0;

    for (int i = 0; i < command.Length; i++) 
    {
        if (command.TabWord[i] != BLANK) 
        {
            count++;
        }
    }

    if (count >= 8)
    {
        Word filename = ConcatWord(StringToWord("CONFIG/save/"), command);
        
        WordToString(filename, namafile);
        FILE *File = fopen(namafile, "w");

        fprintf(File, "%d\n", LengthList(artist)); // jml penyanyi

        int j=0;
        for (int i = 0; i < album_artist.Count; i=idxjump)
        {
            fprintf(File, "%d ", jmlkey(album_artist, album_artist.Elements[i].Value)); // jml album
            writeword(File,album_artist.Elements[i].Value);
            idxjump += jmlkey(album_artist, album_artist.Elements[i].Value);

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
        }

        fprintf(File,"%d\n", user.Neff);//jml user

        for (int i = 0; i < user.Neff; i++)
        {
            writeword(File, user.A[i]);//nama user
        }
    //========================================================================

        for(int idxuser=0;idxuser<user.Neff;idxuser++)
        {
            if(CompareStringWord(playing.A[idxuser],""))
            {
            fprintf(File, "-\n");
            }
            else
            {
                writeword(File, playing.A[idxuser]);
            }//now playing

            fprintf(File,"%d\n", LengthQueue(multi.Elements[idxuser].Queue));//jml queue

            for (int i = 0; i < LengthQueue(multi.Elements[idxuser].Queue); i++)
            {
                writeword(File, multi.Elements[idxuser].Queue.Buffer[i]);//queue
            }

            fprintf(File, "%d\n", multi.Elements[idxuser].History.TOP+1);//jml riwayat

            for (int it = multi.Elements[idxuser].History.TOP; it >= 0; it--)
            {
                writeword(File, multi.Elements[idxuser].History.T[it]);//riwayat
            }

            if(multi.Elements[idxuser].Playlist.Neff==0 && idxuser==user.Neff-1)
            {
                fprintf(File, "%d", multi.Elements[idxuser].Playlist.Neff);//jml playlist untuk user terakhir
            }
            else
            {
                fprintf(File, "%d\n", multi.Elements[idxuser].Playlist.Neff);//jml playlist
            }

            for (int ip = 0; ip < multi.Elements[idxuser].Playlist.Neff; ip++)
            {
                fprintf(File, "%d ",NbElmt(multi.Elements[idxuser].PlaylistSong[ip].Song));//jml lagu

                if(idxuser==user.Neff-1 && ip==multi.Elements[idxuser].Playlist.Neff-1)
                {
                    writewordnnl(File, multi.Elements[idxuser].Playlist.A[ip]);//nama playlist untuk user terakhir
                }
                else
                {
                    writeword(File, multi.Elements[idxuser].Playlist.A[ip]);//nama playlist
                }

                address s = First(multi.Elements[idxuser].PlaylistSong[ip].Song);
                for (int is = 0; is < NbElmt(multi.Elements[idxuser].PlaylistSong[ip].Song); is++)
                {
                    if(idxuser==user.Neff-1 && ip==multi.Elements[idxuser].Playlist.Neff-1 && is==NbElmt(multi.Elements[idxuser].PlaylistSong[ip].Song)-1)
                    {
                        writewordnnl(File, s->info);//judul lagu untuk line terakhir
                    }
                    else
                    {
                    writeword(File, s->info);//judul lagu
                    }
                    s=Next(s);
                }
            }
        }
        fclose(File);

        printf("Save file berhasil disimpan\n");
    }
    else
    {
        printf("%sMinimal terdapat 4 karakter selain \".txt\" dalam nama save file. Silakan coba lagi!\n", RED);
    }
}