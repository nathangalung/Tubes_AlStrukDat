/* FILE help.c */

#include <stdio.h>
#include "help.h"

void help(boolean sesi, boolean menu)
{
    printf("\
    ██╗  ██╗███████╗██╗     ██████╗     ██╗    ██╗ █████╗ ██╗   ██╗ █████╗ ███╗   ██╗ ██████╗ ██╗    ██╗ █████╗ ██╗   ██╗███████╗\n\
    ██║  ██║██╔════╝██║     ██╔══██╗    ██║    ██║██╔══██╗╚██╗ ██╔╝██╔══██╗████╗  ██║██╔════╝ ██║    ██║██╔══██╗██║   ██║██╔════╝\n\
    ███████║█████╗  ██║     ██████╔╝    ██║ █╗ ██║███████║ ╚████╔╝ ███████║██╔██╗ ██║██║  ███╗██║ █╗ ██║███████║██║   ██║█████╗  \n\
    ██╔══██║██╔══╝  ██║     ██╔═══╝     ██║███╗██║██╔══██║  ╚██╔╝  ██╔══██║██║╚██╗██║██║   ██║██║███╗██║██╔══██║╚██╗ ██╔╝██╔══╝  \n\
    ██║  ██║███████╗███████╗██║         ╚███╔███╔╝██║  ██║   ██║   ██║  ██║██║ ╚████║╚██████╔╝╚███╔███╔╝██║  ██║ ╚████╔╝ ███████╗\n\
    ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝          ╚══╝╚══╝ ╚═╝  ╚═╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝  ╚══╝╚══╝ ╚═╝  ╚═╝  ╚═══╝  ╚══════╝\n\
    ");
    if (!sesi && !menu){ // perintah dipanggil sebelum memasuki sesi
        printf("1. START -> Untuk masuk sesi baru \n");
        printf("\t2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi \n");
        printf("\t3. HELP -> Untuk menampilkan bantuan \n");
        printf("\t4. QUIT -> Untuk keluar dari aplikasi \n");
    } else if(sesi && !menu){
        printf("1. LOGIN -> Untuk masuk ke akun yang sudah ada \n");
        printf("\t2. SIGN UP -> Untuk mendaftarkan akun \n");
        printf("\t3. HELP -> Untuk menampilkan bantuan \n");
        printf("\t4. SAVE -> Untuk menyimpan state aplikasi terbaru \n");
        printf("\t5. QUIT -> Untuk keluar dari aplikasi \n");
    } else if (sesi && menu){ // perintah dipanggil setelah memasuki sesi
        printf("1. LIST -> Untuk menampilkan daftar playlist, list penyanyi, list album, dan list lagu \n");    
        printf("\t2. PLAY -> Untuk memutar lagu atau playlist yang dipilih \n");
        printf("\t3. QUEUE -> Untuk memanipulasi queue lagu \n");
        printf("\t4. SONG -> Untuk melakukan navigasi lagu yang ada pada queue \n");
        printf("\t5. PLAYLIST -> Untuk melakukan basic command playlist seperti create, add, swap, remove, dan delete \n");
        printf("\t6. STATUS -> Untuk menampilkan lagu yang sedang dimainkan, queue lagu yang ada, dan playlist lagu diputar \n");
        printf("\t7. SAVE -> Untuk menyimpan state aplikasi terbaru \n");
        printf("\t8. HELP -> Untuk menampilkan bantuan \n");
        printf("\t9. QUIT -> Untuk keluar dari aplikasi \n");
        printf("\t10. LOGOUT -> Untuk keluar dari sesi dan kembali ke menu utama \n");
    }
}

// check fungsi help
// int main()
// {
//     help(false, true);
//     return 0;
// }