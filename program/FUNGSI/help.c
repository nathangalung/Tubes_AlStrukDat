/* FILE help.c */

#include <stdio.h>
#include "help.h"

// ========================================================================================= HELP ======================================================================================================== //

void Help(boolean sesi, boolean menu)
{
    // printf("\
    // ██╗  ██╗███████╗██╗     ██████╗     ██╗    ██╗ █████╗ ██╗   ██╗ █████╗ ███╗   ██╗ ██████╗ ██╗    ██╗ █████╗ ██╗   ██╗███████╗\n\
    // ██║  ██║██╔════╝██║     ██╔══██╗    ██║    ██║██╔══██╗╚██╗ ██╔╝██╔══██╗████╗  ██║██╔════╝ ██║    ██║██╔══██╗██║   ██║██╔════╝\n\
    // ███████║█████╗  ██║     ██████╔╝    ██║ █╗ ██║███████║ ╚████╔╝ ███████║██╔██╗ ██║██║  ███╗██║ █╗ ██║███████║██║   ██║█████╗  \n\
    // ██╔══██║██╔══╝  ██║     ██╔═══╝     ██║███╗██║██╔══██║  ╚██╔╝  ██╔══██║██║╚██╗██║██║   ██║██║███╗██║██╔══██║╚██╗ ██╔╝██╔══╝  \n\
    // ██║  ██║███████╗███████╗██║         ╚███╔███╔╝██║  ██║   ██║   ██║  ██║██║ ╚████║╚██████╔╝╚███╔███╔╝██║  ██║ ╚████╔╝ ███████╗\n\
    // ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝          ╚══╝╚══╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝  ╚══╝╚══╝ ╚═╝  ╚═╝  ╚═══╝  ╚══════╝\n\
    // ");
    printf("\n==================================[ Menu Help WayangWave ]==================================");
    if (!sesi && !menu){ // perintah dipanggil sebelum memasuki sesi
        printf("\n1. START -> Untuk masuk sesi baru \n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi \n");
        printf("3. HELP -> Untuk menampilkan bantuan \n");
        printf("4. QUIT -> Untuk keluar dari aplikasi \n");
    } else if(!sesi && menu){
        printf("\n1. LOGIN -> Untuk masuk ke akun yang sudah ada \n");
        printf("2. SIGN UP -> Untuk mendaftarkan akun \n");
        printf("3. HELP -> Untuk menampilkan bantuan \n");
        printf("4. SAVE -> Untuk menyimpan state aplikasi terbaru \n");
        printf("5. QUIT -> Untuk keluar dari aplikasi \n");
    } else if (sesi && menu){ // perintah dipanggil setelah memasuki sesi
        printf("\n1. LIST -> Untuk menampilkan daftar playlist, list penyanyi, list album, dan list lagu \n");    
        printf("2. PLAY -> Untuk memutar lagu atau playlist yang dipilih \n");
        printf("3. QUEUE -> Untuk memanipulasi queue lagu \n");
        printf("4. SONG -> Untuk melakukan navigasi lagu yang ada pada queue \n");
        printf("5. PLAYLIST -> Untuk melakukan basic command playlist seperti create, add, swap, remove, dan delete \n");
        printf("6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan, queue lagu yang ada, dan playlist lagu diputar \n");
        printf("7. SAVE -> Untuk menyimpan state aplikasi terbaru \n");
        printf("8. HELP -> Untuk menampilkan bantuan \n");
        printf("9. QUIT -> Untuk keluar dari aplikasi \n");
        printf("10. LOGOUT -> Untuk keluar dari sesi dan kembali ke menu utama \n");
    }
}