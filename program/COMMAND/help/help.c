/* FILE help.c */

#include <stdio.h>
#include "boolean.h"

void help(boolean isStart)
{
    printf("\
    ██╗  ██╗███████╗██╗     ██████╗     ██╗    ██╗ █████╗ ██╗   ██╗ █████╗ ███╗   ██╗ ██████╗ ██╗    ██╗ █████╗ ██╗   ██╗███████╗\n\
    ██║  ██║██╔════╝██║     ██╔══██╗    ██║    ██║██╔══██╗╚██╗ ██╔╝██╔══██╗████╗  ██║██╔════╝ ██║    ██║██╔══██╗██║   ██║██╔════╝\n\
    ███████║█████╗  ██║     ██████╔╝    ██║ █╗ ██║███████║ ╚████╔╝ ███████║██╔██╗ ██║██║  ███╗██║ █╗ ██║███████║██║   ██║█████╗  \n\
    ██╔══██║██╔══╝  ██║     ██╔═══╝     ██║███╗██║██╔══██║  ╚██╔╝  ██╔══██║██║╚██╗██║██║   ██║██║███╗██║██╔══██║╚██╗ ██╔╝██╔══╝  \n\
    ██║  ██║███████╗███████╗██║         ╚███╔███╔╝██║  ██║   ██║   ██║  ██║██║ ╚████║╚██████╔╝╚███╔███╔╝██║  ██║ ╚████╔╝ ███████╗\n\
    ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝          ╚══╝╚══╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝  ╚══╝╚══╝ ╚═╝  ╚═╝  ╚═══╝  ╚══════╝\n\
    ");
    if (!isStart) // perintah dipanggil sebelum memasuki sesi
    {
        printf("1. START -> Untuk masuk sesi baru \n");
        printf("\t2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi \n");
        printf("\t3. HELP -> Untuk menampilkan bantuan \n");
        printf("\t4. QUIT -> Untuk keluar dari aplikasi \n");
    }
    else // perintah dipanggil setelah memasuki sesi
    {
        printf("1. LIST -> Untuk menampilkan daftar playlist, list penyanyi, list album, dan list lagu \n");    
        printf("\t2. PLAY -> Untuk memutar lagu atau playlist yang dipilih \n");
        printf("\t3. QUEUE -> Untuk memanipulasi queue lagu \n");
        printf("\t4. SONG -> Untuk melakukan navigasi lagu yang ada pada queue \n");
        printf("\t5. PLAYLIST -> Untuk melakukan basic command playlist seperti create, add, swap, remove, dan delete \n");
        printf("\t6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan serta queue song yang ada dan playlist lagu diputar \n");
        printf("\t7. SAVE -> Untuk menyimpan state aplikasi terbaru \n");
        printf("\t8. HELP -> Untuk menampilkan bantuan \n");
        printf("\t9. QUIT -> Untuk keluar dari aplikasi \n");
    }
}

// check fungsi help
// int main()
// {
//     help(true);
//     return 0;
// }