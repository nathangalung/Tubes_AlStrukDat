#include <stdio.h>
#include <stdlib.h>

#include "user.h"

int main()
{
    int sum_user, sum_queue, sum_history, sum_playlist, sum_song;
    User multi;
    Word queue_input, history_input, playlist_input, song_input;

    CreateEmptyUser(&multi);

    printf("\nMasukkan jumlah user : ");
    StartWordMark();
    sum_user = atoi(currentWord.TabWord);

    for (int i = 0; i < sum_user; i++)
    {
        InsertLastUser(&multi);
        CreateEmptyQueue(&multi.Elements[i].Queue);
        CreateEmptyStack(&multi.Elements[i].History);
        CreateEmptyDynamic(&multi.Elements[i].Playlist);

        printf("\nMasukkan jumlah queue : ");
        StartWordMark();
        printf("\n");
        sum_queue = atoi(currentWord.TabWord);

        for (int j = 0; j < sum_queue; j++)
        {
            printf("Masukkan queue ke-%d : ", (j + 1));
            StartWordMark();
            Enqueue(&multi.Elements[i].Queue, currentWord);
        }

        printf("\nMasukkan jumlah history : ");
        StartWordMark();
        printf("\n");
        sum_history = atoi(currentWord.TabWord);

        for (int j = 0; j < sum_history; j++)
        {
            printf("Masukkan history ke-%d : ", (j + 1));
            StartWordMark();
            PushStack(&multi.Elements[i].History, currentWord);
        }

        printf("\nMasukkan jumlah playlist : ");
        StartWordMark();
        printf("\n");
        sum_playlist = atoi(currentWord.TabWord);

        for (int j = 0; j < sum_playlist; j++)
        {
            printf("Masukkan playlist ke-%d : ", (j + 1));
            StartWordMark();
            InsertLastDynamic(&multi.Elements[i].Playlist, currentWord);

            CreateEmptyLinier(&multi.Elements[i].PlaylistSong[j].Song);
        }

        for (int j = 0; j < sum_playlist; j++)
        {
            printf("\nMasukkan jumlah lagu dalam playlist ke-%d : ", (j + 1));
            StartWordMark();
            printf("\n");
            sum_song = atoi(currentWord.TabWord);

            for (int k = 0; k < sum_song; k++)
            {
                printf("Masukkan lagu ke-%d dalam playlist ke-%d : ", (k + 1), (j + 1));
                StartWordMark();
                InsVLast(&multi.Elements[i].PlaylistSong[j].Song, currentWord);
            }
        }   
    }

    for (int i = 0; i < multi.Count; i++)
    {
        printf("\nUser %d :", (i + 1));

        printf("\nQueue : ");
        for (int j = 0; j < LengthQueue(multi.Elements[i].Queue); j++)
        {
            printf("\n\t%d. ", (j + 1));\
            DisplayWord(multi.Elements[i].Queue.Buffer[j]);
        }
        printf("\n");

        printf("\nHistory : ");
        for (int j = 0; j < (Top(multi.Elements[i].History) + 1); j++)
        {
            printf("\n\t%d. ", (j + 1));\
            DisplayWord(multi.Elements[i].History.T[j]);
        }
        printf("\n");
        
        printf("\nPlaylist : ");
        for (int j = 0; j < LengthListDynamic(multi.Elements[i].Playlist); j++)
        {
            printf("\n\t%d. ", (j + 1));
            DisplayWord(multi.Elements[i].Playlist.A[j]);
        }

        for (int j = 0; j < LengthListDynamic(multi.Elements[i].Playlist); j++)
        {
            printf("\nLagu Playlist %d : ", (j + 1));
            address P = First(multi.Elements[i].PlaylistSong[j].Song);
            for (int k = 0; k < NbElmt(multi.Elements[i].PlaylistSong[j].Song); k++)
            {
                printf("\n\t%d. ", (k + 1));
                DisplayWord(Info(P));
                P = Next(P);
            }
            printf("\n");
        }
    }
}