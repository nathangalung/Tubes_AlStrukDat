/* File queue.c */

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void CreateEmptyQueue(Queue *queue)
{
    IDX_HEAD(*queue) = IDX_UNDEF;
    IDX_TAIL(*queue) = IDX_UNDEF;
}

boolean IsQueueEmpty(Queue queue)
{
    return ((IDX_HEAD(queue) == IDX_UNDEF) && (IDX_TAIL(queue) == IDX_UNDEF));
}

boolean IsQueueFull(Queue queue)
{
    return (LengthQueue(queue) == CAPACITY-1);
}

boolean IsQueueMember(Queue queue, int index)
{
    int i = 0;
    boolean found = false;
    for (i=0; i <= IDX_TAIL(queue); i++){
        if (index == i) {
            found = true;
        }
    }
    return found;

}

int LengthQueue(Queue queue)
{
    int length;

    if (IsQueueEmpty(queue))
    {
        length = 0;
    }
    else if (IDX_TAIL(queue) >= IDX_HEAD(queue))
    {
        length = (IDX_TAIL(queue) - IDX_HEAD(queue)) + 1;
    }
    else
    {
        length = (IDX_TAIL(queue) - IDX_HEAD(queue)) + (CAPACITY + 1);
    }

    return (length);
}

void Enqueue(Queue *queue, Word word)
{
    if (IsQueueEmpty(*queue))
    {
        IDX_HEAD(*queue) = 0;
        IDX_TAIL(*queue) = 0;
    }
    else
    {
        int i;
        if (IDX_HEAD(*queue) != 0)
        {
            for (i=IDX_HEAD(*queue); i <= IDX_TAIL(*queue); i++)
            {
                (*queue).Buffer[i - IDX_HEAD(*queue)] = (*queue).Buffer[i];
            }
            IDX_TAIL(*queue) += 1;
        } 
        else if (IDX_TAIL(*queue) == CAPACITY-1)
        {
            IDX_TAIL(*queue) += 1;
        }
        else
        {
            IDX_TAIL(*queue)++;
        }
    } 
    TAIL(*queue) = word;
}

void Dequeue(Queue *queue, Word *word)
{
    *word = HEAD(*queue);
    if (IDX_HEAD(*queue) == IDX_TAIL(*queue))
    {
        IDX_HEAD(*queue) = IDX_UNDEF;
        IDX_TAIL(*queue) = IDX_UNDEF; 
    }
    else
    {
        for (int i = 0; i < (LengthQueue(*queue) - 1); i++)
        {
            queue->Buffer[i] = queue->Buffer[i+1];
        }
        IDX_TAIL(*queue)--;
    }
}