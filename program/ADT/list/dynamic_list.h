/* file dynamic_list.h */

#include "../../boolean.h"
#include "../machine/wordmachine.h"

#ifndef __DYNAMIC_LIST_H__
#define __DYNAMIC_LIST_H__

#define IdxType int
#define MaxElDynamic 100

typedef struct
{
    Word *A;
    int Neff;
} DynamicList;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong  */
void CreateEmptyDynamic(DynamicList *list);
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** DESTRUKTOR ********** */
void DealokasiDynamic(DynamicList *list);
/* I.S. L terdefinisi; */
/* F.S. (L) dikembalikan ke system, melakukan dealokasi/pengembalian */
/* memori ke system */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmptyDynamic(DynamicList list);
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* *** Test list penuh *** */
boolean IsFullDynamic(DynamicList list);
/* Mengirimkan true jika list L penuh, mengirimkan false jika tidak */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthDynamic(DynamicList list);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Menghasilkan sebuah elemen *** */
Word GetDynamic(DynamicList list, IdxType i);
/* Prekondisi : list tidak kosong, i antara FirstIdxList(L)..LastIdxList(L) */
/* Mengirimkan elemen list yang ke-i */

void InsertLastDynamic(DynamicList *list, Word word);

#endif