#include <stdio.h>

#include "multi.h"
// ========================================================================================= LOGIN ======================================================================================================== //
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
            if (CompareWord(currentWord, user->A[ctr]))
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
            printf("\nBerhasil masuk. Selamat datang, \"");
            DisplayWord(currentWord);
            printf("\" dan selamat bersenang-senang!\n");
        }
        else
        {
            printf("\nTidak ada user dengan username \"");
            DisplayWord(currentWord);
            printf("\"\n");
            printf("\nBerikut daftar username yang terdaftar :\n");
            for (int i = 0; i < LengthListDynamic(*user); i++)
            {
                printf("\t%d. ", (i+1));
                DisplayWord(user->A[i]);
                printf("\n");
            }
            printf("\n");
        }
    }

    return idx_user;
}
// ========================================================================================= LOGOUT ======================================================================================================== //
void Logout(DynamicList *user, int idx_user)
{
    printf("Berhasil keluar. Sampai jumpa lagi, \"");
    DisplayWord(user->A[idx_user]);
    printf("\" dan elamat beraktivitas kembali!:)\n");
}
// ========================================================================================= REGISTER ======================================================================================================== //
void Register(DynamicList *user, User *multi)
{
    boolean found = false;
    int ctr = 0, count = 0;

    printf("Masukkan username user baru WayangWave : ");
    StartWordBlank();

    for (int i = 0; i < currentWord.Length; i++) 
    {
        if (currentWord.TabWord[i] != BLANK) 
        {
            count++;
        }
    }

    if (count >= 3)
    {
        while (!found && ctr < LengthListDynamic(*user))
        {
            if (CompareWord(currentWord, user->A[ctr]))
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
            printf("\nUsername \"");
            DisplayWord(currentWord);
            printf("\" sudah didaftarkan, silakan gunakan username lain!\n");
        }
        else
        {
            found = true;

            CreateEmptyQueue(&multi->Elements[LengthListDynamic(*user)].Queue);
            CreateEmptyStack(&multi->Elements[LengthListDynamic(*user)].History);
            CreateEmptyDynamic(&multi->Elements[LengthListDynamic(*user)].Playlist);

            InsertLastDynamic(user, currentWord);
            printf("\nUsername \"");
            DisplayWord(currentWord);
            printf("\" berhasil didaftarkan, silakan login kembali!\n");
        }
    }
    else
    {
        printf("\nMinimal terdapat 3 karakter selain whitespace dalam username user. Silakan coba lagi!");
    }
}