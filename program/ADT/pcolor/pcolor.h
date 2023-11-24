#ifndef __PCOLOR_H__
#define __PCOLOR_H__

#define NORMAL "\x1B[0m"
#define BLACK "\x1B[30m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define WHITE "\x1B[37m"

void print_red(char *c);
/*I.S   -*/
/*FS    Menampilkan output berupa string dengan warna merah
        Setelah selesai kembali ke warna normal/putih*/

void print_green(char *c);
/*I.S   -*/
/*FS    Menampilkan output berupa string dengan warna hijau
        Setelah selesai kembali ke warna normal/putih*/

void print_yellow(char *c);
/*I.S   -*/
/*FS    Menampilkan output berupa string dengan warna kuning
        Setelah selesai kembali ke warna normal/putih*/

#endif