#include <stdio.h>

#include "multi.h"

void Login(DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist, LinierList *palylist_song)
{
    boolean found = false;
    

    while (!found)
    {
        int ctr = 0;
        printf("Masukkan username user WayangWave : ");
        StartWordBlank();
        while (!found && ctr < LengthListDynamic(*user))
        {
            if (CompareWord1(currentWord, user->A[ctr]))
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

void Logout(DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist, LinierList *palylist_song)
{
    printf("Berhasil keluar. Sampai jumpa lagi!");
}

void SignUp(DynamicList *user, Queue *queue, Stack *history, DynamicList *playlist, LinierList *palylist_song)
{
    printf("Masukkan username user WayangWave : ");
}