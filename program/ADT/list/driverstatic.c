#include <stdio.h>
#include "static_list.h"

int main()
{
    /* Test Konstruktor */
    StaticList L1, L2;
    CreateEmptyStatic(&L1);
    CreateEmptyStatic(&L2);
    printf("L1: %d\n", IsListEmpty(L1));
    printf("L2: %d\n", IsListEmpty(L2));

    /* Test Insert dan Search */
    InsertFirstList(&L1, 5);
    InsertFirstList(&L1, 15);
    InsertFirstList(&L1, 25);
    printf("Isi L1: ");
    for (int i = FirstIdxList(L1); i <= LastIdxList(L1); i++)
    {
        printf("%d ", L1.A[i]);
    }
    printf("\n");
    printf("Search 15 in L1: %s\n", SearchList(L1, 15) ? "Ditemukan" : "Tidak ditemukan");
    printf("Search 30 in L1: %s\n", SearchList(L1, 30) ? "Ditemukan" : "Tidak ditemukan");

    /* Test Delete */
    DeleteFirstList(&L1);
    printf("Setelah menghapus elemen pertama, isi L1: ");
    for (int i = FirstIdxList(L1); i <= LastIdxList(L1); i++)
    {
        printf("%d ", L1.A[i]);
    }
    printf("\n");

    DeleteLastList(&L1);
    printf("Setelah menghapus elemen terakhir, isi L1: ");
    for (int i = FirstIdxList(L1); i <= LastIdxList(L1); i++)
    {
        printf("%d ", L1.A[i]);
    }
    printf("\n");

    int elemenHapus = 15;
    if (SearchList(L1, elemenHapus))
    {
        int idxElemenHapus = -1;
        for (int i = FirstIdxList(L1); i <= LastIdxList(L1); i++)
        {
            if (L1.A[i] == elemenHapus)
            {
                idxElemenHapus = i;
                break;
            }
        }
        DeleteListAt(&L1, idxElemenHapus);
    }
    printf("Setelah menghapus elemen %d, isi L1: ", elemenHapus);
    for (int i = FirstIdxList(L1); i <= LastIdxList(L1); i++)
    {
        printf("%d ", L1.A[i]);
    }
    printf("\n");

    /* Test Concat */
    List L3 = ConcatList(L1, L2);
    printf("Isi L3 (Hasil Concat L1 dan L2): ");
    for (int i = FirstIdxList(L3); i <= LastIdxList(L3); i++)
    {
        printf("%d ", L3.A[i]);
    }
    printf("\n");

    return 0;
}