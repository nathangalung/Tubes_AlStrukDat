#include <stdio.h>

#include "multi.h"

int Login(DynamicList *user, User *multi, int idx_user)
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
            else
            {   
                ctr++;
            }
        }

        if (found)
        {
            idx_user = ctr;
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

    return idx_user;
}

int Logout(User *multi, int idx_user)
{
    idx_user = -1;
    printf("Berhasil keluar. Sampai jumpa lagi!\n");

    return idx_user;
}

int SignUp(DynamicList *user, User *multi, int idx_user)
{
    idx_user = 2;
    printf("Masukkan username user WayangWave : ");

    return idx_user;
}