#include <stdio.h>
#include "dynamic_list.h"

int main()
{
    /* Test Konstruktor */
    DynamicList L1 = MakeListDynamic();
    DynamicList L2 = MakeListDynamic();
    printf("L1: %d\n", IsListEmptyDynamic(L1));
    printf("L2: %d\n", IsListEmptyDynamic(L2));

    /* Test Insert dan Search */
    ElType elemen1 = 5;
    ElType elemen2 = 15;
    ElType elemen3 = 25;

    L1.A[L1.Neff] = elemen1;
    L1.Neff++;
    L1.A[L1.Neff] = elemen2;
    L1.Neff++;
    L1.A[L1.Neff] = elemen3;
    L1.Neff++;

    printf("Isi L1: ");
    for (int i = 0; i < LengthListDynamic(L1); i++)
    {
        printf("%d ", GetDynamic(L1, i));
    }
    printf("\n");
    printf("Search 15 in L1: %s\n", SearchList(L1, 15) ? "Ditemukan" : "Tidak ditemukan");
    printf("Search 30 in L1: %s\n", SearchList(L1, 30) ? "Ditemukan" : "Tidak ditemukan");

    /* Test Delete */
    if (SearchList(L1, elemen2))
    {
        int idxElemenHapus = -1;
        for (int i = 0; i < LengthListDynamic(L1); i++)
       
