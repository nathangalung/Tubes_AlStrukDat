/* file dynamic_list.c */

#include <stdio.h>
#include <stdlib.h>
#include "dynamic_list.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong  */
DynamicList MakeListDynamic()
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
{
    /* KAMUS LOKAL */
    List L;
    /* ALGORITMA */
    L.A = (ElType *) malloc (MaxEl * sizeof(ElType));
    if (L.A != NULL)
    {
        L.Neff = 0;
    }
    return L;
}

/* ********** DESTRUKTOR ********** */
void DealokasiDynamic(DynamicList *L)
/* I.S. L terdefinisi; */
/* F.S. (L) dikembalikan ke system, melakukan dealokasi/pengembalian */
/* memori ke system */
{
    free(L->A);
    L->Neff = 0;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsListEmptyDynamic(DynamicList L)
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
{
    return (L.Neff == 0);
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetDynamic(DynamicList L, IdxType i)
/* Prekondisi : list tidak kosong, i antara FirstIdxList(L)..LastIdxList(L) */
/* Mengirimkan elemen list yang ke-i */
{
    return (L.A[i]);
}

/* *** Test list penuh *** */
boolean IsListFullDynamic(DynamicList L)
/* Mengirimkan true jika list L penuh, mengirimkan false jika tidak */
{
    return (L.Neff == MaxEl);
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthListDynamic(DynamicList L)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
{
    return (L.Neff);
}