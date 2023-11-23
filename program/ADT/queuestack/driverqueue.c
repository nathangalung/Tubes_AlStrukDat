#include <stdio.h>
#include "queue.h"

int main ()
{
    Queue queue;
    printf("FILE DRIVER QUEUE.H - MEMBALIKKAN URUTAN QUEUE\n");
    printf("Masukkan length queue : ");
    StartWordMark();
    printf("\n");
    CreateEmptyQueue(&queue);
    int len = WordToInt(currentWord);
    printf("Masukkan queue : \n");

    for (int i = 0; i < len; i++)
    {
        StartWordMark();
        Enqueue(&queue, currentWord);
    }
    printf("\nQueue saat ini : [");
    for (int i = IDX_HEAD(queue); i <= IDX_TAIL(queue); i++)
    {
        DisplayWord(queue.Buffer[i]);
        if (i != IDX_TAIL(queue)) {
            printf(",");
        }
    }
    printf("]\n");
    int index = 0;
    printf("Queue : \n");
    while (!IsQueueEmpty(queue))
    {
        printf("%d. ", index+1);
        Word deq;
        Dequeue(&queue, &deq);
        DisplayWord(deq);
        printf("\n");
        index++;
    }
    return 0;
}