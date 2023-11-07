/* file dynamic_list.h */

#include "../boolean.h"

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#define IdxType int
#define ElType int
#define MaxEl 100
#define Mark ;

typedef struct
{
    ElType *A;
    int Neff;
} DynamicList;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong  */
List MakeListDynamic();
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** DESTRUKTOR ********** */
void DealokasiDynamic(List *L);
/* I.S. L terdefinisi; */
/* F.S. (L) dikembalikan ke system, melakukan dealokasi/pengembalian */
/* memori ke system */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsListEmptyDynamic(List L);
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthListDynamic(List L);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Menghasilkan sebuah elemen *** */
ElType GetDynamic(List L, IdxType i);
/* Prekondisi : list tidak kosong, i antara FirstIdxList(L)..LastIdxList(L) */
/* Mengirimkan elemen list yang ke-i */

/* *** Test list penuh *** */
boolean IsListFullDynamic(List L);
/* Mengirimkan true jika list L penuh, mengirimkan false jika tidak */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthListDynamic(List L);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
<<<<<<< HEAD

=======
>>>>>>> d4334d0c46d527b1268a3836b5c752715433264e
#endif