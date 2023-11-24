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
        while (!found && ctr < LengthDynamic(*user))
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
            printf("%s\nTidak ada user dengan username \"", RED);
            DisplayWord(currentWord);
            printf("\"\n");
            printf("%s\nBerikut daftar username yang terdaftar :\n", WHITE);
            for (int i = 0; i < LengthDynamic(*user); i++)
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
    printf("\" dan selamat beraktivitas kembali!:)\n");
}
// ========================================================================================= REGISTER ======================================================================================================== //
void SignUp(DynamicList *user, User *multi)
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
        while (!found && ctr < LengthDynamic(*user))
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
            printf("%s\nUsername \"", RED);
            DisplayWord(currentWord);
            printf("\" sudah didaftarkan, silakan gunakan username lain!\n");
        }
        else
        {
            found = true;

            CreateEmptyQueue(&multi->Elements[LengthDynamic(*user)].Queue);
            CreateEmptyStack(&multi->Elements[LengthDynamic(*user)].History);
            CreateEmptyDynamic(&multi->Elements[LengthDynamic(*user)].Playlist);

            InsertLastDynamic(user, currentWord);
            printf("\nUsername \"");
            DisplayWord(currentWord);
            printf("\" berhasil didaftarkan, silakan login kembali!\n");
        }
    }
    else
    {
        printf("%s\nMinimal terdapat 3 karakter selain whitespace dalam username user. Silakan coba lagi!", RED);
    }
}