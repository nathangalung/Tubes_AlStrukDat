/* file driver_static_list.c */

#include <stdio.h>
#include "static_list.h"

int main() {
    // Inisialisasi static list
    StaticList myList;
    CreateEmptyStatic(&myList);

    // Menambahkan elemen ke static list
    printf("Menambahkan kata 'Halo' ke dalam static list...\n");
    Word kata1;
    kata1  = "Halo";
    InsertLastStatic(&myList, kata1);

    // Menampilkan isi static list
    printf("\nIsi static list:\n");
    for (int i = 0; i < LengthStatic(myList); i++) {
        printf("Elemen ke-%d: %s\n", i + 1, GetStatic(myList, i));
    }

    // Mengecek apakah static list kosong atau tidak
    printf("\nApakah static list kosong? %s\n", IsEmptyStatic(myList) ? "Ya" : "Tidak");

    // Mengecek apakah static list penuh atau tidak
    printf("Apakah static list penuh? %s\n", IsFullStatic(myList) ? "Ya" : "Tidak");

    return 0;
}
