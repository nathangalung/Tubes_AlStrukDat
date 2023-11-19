#include <stdio.h>

#include "login.h"

void login(DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist)
{
    boolean found = false;
    int ctr = 0;

    while (!found)
    {
        printf("Masukkan username user WayangWave : ");
        StartWordBlank();

        while (!found && ctr < LengthListDynamic(*user))
        {
            if (CompareWord1(user->A[ctr], currentWord))
            {
                found = true;
            }
            ctr++;
        }

        if (found)
        {
            printf("Berhasil masuk. Selamat datang, ");
            DisplayWord(currentWord);
            printf("!\n");
        }
        else
        {
            printf("Tidak ada user dengan username \"");
            DisplayWord(currentWord);
            printf("\"\n");
        }
    }

    
}