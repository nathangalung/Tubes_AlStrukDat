/* file driver_dynamic_list.c */

#include <stdio.h>
#include "dynamic_list.h"

int main() {
    // Inisialisasi dynamic list
    DynamicList myList;
    CreateEmptyDynamic(&myList);

    // Menambahkan elemen ke dynamic list
    printf("Menambahkan kata 'Halo' ke dalam dynamic list...\n");
    Word kata1;
    kata1 = "Halo";
    InsertLastDynamic(&myList, kata1);

    // Menampilkan isi dynamic list
    printf("\nIsi dynamic list:\n");
    for (int i = 0; i < LengthDynamic(myList); i++) {
        printf("Elemen ke-%d: %s\n", i + 1, GetDynamic(myList, i));
    }

    // Mengecek apakah dynamic list kosong atau tidak
    printf("\nApakah dynamic list kosong? %s\n", IsEmptyDynamic(myList) ? "Ya" : "Tidak");

    // Mengecek apakah dynamic list penuh atau tidak
    printf("Apakah dynamic list penuh? %s\n", IsFullDynamic(myList) ? "Ya" : "Tidak");

    // Dealokasi dynamic list
    DealokasiDynamic(&myList);

    // Mengecek apakah dynamic list kosong setelah dealokasi
    printf("\nSetelah dealokasi, apakah dynamic list kosong? %s\n", IsEmptyDynamic(myList) ? "Ya" : "Tidak");

    return 0;
}
