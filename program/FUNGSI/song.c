#include "song.h"
#include <stdio.h>
#include <stdlib.h>

void SongNext(User *multi, StaticList artist, DynamicList *playing, int idx_user)
{
    Word currentSong = playing->A[idx_user];
    Word temp;
    
    if (IsQueueEmpty(multi->Elements[idx_user].Queue))
    {
        printf("Queue kosong, memutar kembali lagu \"");
        DisplayWord(SplitWordMark(SplitWordMark(currentSong)));
        printf("\" oleh \"");
        DisplayWord(SplitWordLeftMark(currentSong));
        printf("\"\n");
    }
    else
    {
        Dequeue(&multi->Elements[idx_user].Queue, &temp);
        PushStack(&multi->Elements[idx_user].History, currentSong);
        playing->A[idx_user] = temp;
        currentSong = playing->A[idx_user];

        printf("Memutar lagu selanjutnya \"");
        DisplayWord(SplitWordMark(SplitWordMark(currentSong)));
        printf("\" oleh \"");
        DisplayWord(SplitWordLeftMark(currentSong));
        printf("\"\n");
    }
}

void SongPrevious(User *multi, StaticList artist, DynamicList *playing, int idx_user)
{
    Word previousSong, currentSong = playing->A[idx_user];

    if (IsEmptyStack(multi->Elements[idx_user].History))
    {
        printf("Riwayat lagu kosong, memutar kembali lagu \"");
        DisplayWord(SplitWordMark(SplitWordMark(currentSong)));
        printf("\" oleh \"");
        DisplayWord(SplitWordLeftMark(currentSong));
        printf("\"\n");
    }
    else
    {
        PopStack(&multi->Elements[idx_user].History, &previousSong);
        Word newQueue;
        Queue temp;
        CreateEmptyQueue(&temp);
        
        Enqueue(&temp, currentSong);
        playing->A[idx_user] = previousSong;

        int len = LengthQueue(multi->Elements[idx_user].Queue);

        for (int i = 0; i < len; i++)
        {
            Dequeue(&multi->Elements[idx_user].Queue, &newQueue);
            Enqueue(&temp, newQueue);
        }

        multi->Elements[idx_user].Queue = temp;

        printf("Memutar lagu sebelumnya \"");
        DisplayWord(SplitWordMark(SplitWordMark(previousSong)));
        printf("\" oleh \"");
        DisplayWord(SplitWordLeftMark(previousSong));
        printf("\"\n");
    }
}