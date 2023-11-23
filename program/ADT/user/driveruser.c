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
        CreateEmptyQueue(&multi.Elements[i].Queue);
        CreateEmptyStack(&multi.Elements[i].History);
        CreateEmptyDynamic(&multi.Elements[i].Playlist);

        printf("\nMasukkan jumlah queue : \n");
        StartWordMark();
        sum_queue = atoi(currentWord.TabWord);

        for (int j = 0; j < sum_queue; j++)
        {
            printf("\nMasukkan queue ke-%d : ", (j + 1));
            StartWordMark();
            Enqueue(&multi.Elements[i].Queue, currentWord);
        }

        printf("\nMasukkan jumlah history : \n");
        StartWordMark();
        sum_history = atoi(currentWord.TabWord);

        for (int j = 0; j < sum_history; j++)
        {
            printf("\nMasukkan history ke-%d : ", (j + 1));
            StartWordMark();
            PushStack(&multi.Elements[i].History, currentWord);
        }

        printf("\nMasukkan jumlah playlist : \n");
        StartWordMark();
        sum_playlist = atoi(currentWord.TabWord);

        for (int j = 0; j < sum_playlist; j++)
        {
            printf("\nMasukkan playlist ke-%d : ", (j + 1));
            StartWordMark();
            InsertLastDynamic(&multi.Elements[i].Playlist, currentWord);

            CreateEmptyLinier(&multi.Elements[i].PlaylistSong[j].Song);

            printf("\nMasukkan jumlah lagu dalam playlist ke-%d : \n", (j + 1));
            StartWordMark();
            sum_song = atoi(currentWord.TabWord);

            for (int k = 0; k < sum_song; k++)
            {
                printf("\nMasukkan lagu ke-%d dalam playlist ke-%d: ", (k + 1), (j + 1));
                StartWordMark();
                InsVLast(&multi.Elements[i].PlaylistSong->Song, currentWord);
            }
        }
    }

    for (int i = 0; i < sum_user; i++)
    {
        printf("\nUser %d :", (i + 1));

        printf("\n\tQueue : ");
        for (int j = 0; j < sum_queue; j++)
        {
            printf("\n\t\t%d. ", (j + 1));\
            DisplayWord(multi.Elements[i].Queue.Buffer[j]);
        }
        printf("\n");

        printf("\n\tHistory : ");
        for (int j = 0; j < sum_history; j++)
        {
            printf("\n\t\t%d. ", (j + 1));\
            DisplayWord(multi.Elements[i].History.T[j]);
        }
        printf("\n");
        
        printf("\n\tPlaylist : ");
        for (int j = 0; j < sum_playlist; j++)
        {
            printf("\n\t\t%d. ", (j + 1));
            DisplayWord(multi.Elements[i].Playlist.A[j]);

            printf("\n\t\tLagu : ");
            for (int k = 0; k < sum_song; k++)
            {
                address P = First(multi.Elements[i].PlaylistSong[j].Song);
                printf("\n\t\t\t%d. ", (k + 1));
                DisplayWord(Info(P));
                P = Next(P);
            }
            printf("\n");
        }
        printf("\n");
    }
}