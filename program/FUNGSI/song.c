#include "song.h"
#include <stdio.h>
#include <stdlib.h>

void songNext(User multi, StaticList artist, StaticList *playing, int idx_user){
    Word currentSong = playing->A[idx_user];

}

void songPrevious(User *multi, StaticList artist, StaticList *playing, int idx_user) {
    Word previousSong;
    Word currentSong = playing->A[idx_user];
    if (IsEmptyStack(multi->Elements[idx_user].History)) {
        printf("\nRiwayat lagu kosong, memutar kembali lagu\n\"");
        DisplayWord(SplitWordMark(SplitWordMark(currentSong)));
        printf("\" oleh \"");
        DisplayWord(SplitWordLeft(currentSong));
        printf("\"\n");

    } else {
        PopStack(&multi->Elements[idx_user].History, &previousSong);
        Word newQueue;
        Queue temp;
        
        Enqueue(&temp, currentSong);
        playing->A[idx_user] = previousSong;

        for (int i = 0; i < LengthQueue(multi->Elements[idx_user].Queue); i++)
        {
            Dequeue(&multi->Elements[idx_user].Queue, &newQueue);
            Enqueue(&temp, newQueue);
        }
        CreateEmptyQueue(&multi->Elements[idx_user].Queue);
        multi->Elements[idx_user].Queue = temp;

        printf("\nMemutar lagu sebelumnya\n\"");
        DisplayWord(SplitWordMark(SplitWordMark(previousSong)));
        printf("\" oleh \"");
        DisplayWord(SplitWordLeft(previousSong));
        printf("\"\n");
    }
}