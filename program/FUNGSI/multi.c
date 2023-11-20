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
            printf("Berikut list username yang terdaftar :\n");
            for (int i = 0; i < LengthListDynamic(*user); i++)
            {
                printf("%d. ", (i+1));
                DisplayWord(user->A[i]);
                printf("\n");
            }
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

void SignUp(DynamicList *user)
{
    boolean found_1 = false;
    int ctr = 0;

    while (!found_1)
    {
        boolean found_2 = false;
        printf("Masukkan username user baru WayangWave : ");
        StartWordBlank();

        while (!found_2 && ctr < LengthListDynamic(*user))
        {
            if (CompareWord1(currentWord, user->A[ctr]))
            {
                found_2 = true;
            }
            else
            {
                ctr++;
            }
        }

        if (found_2)
        {
            printf("Username user sudah didaftarkan! Silakan gunakan username lain!\n");
        }
        else
        {
            found_1 = true;
            InsertLastDynamic(user, currentWord);
            printf("Username user berhasil didaftarkan! Silakan login kembali!\n");
        }
    }
}