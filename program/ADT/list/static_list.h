/* file static_list.h */

/* MODUL LIST INTEGER */
/* Berisi definisi dan semua primitif pemrosesan list integer */
/* Penempatan elemen selalu rapat kiri */

#ifndef __STATIC_LIST_H__
#define __STATIC_LIST_H__

#include "../../boolean.h"
#include "../machine/wordmachine.h"


/* Kamus Umum */
#define MaxElStatic 100
#define MarkStatic "-"  /* Nilai tak terdefinisi */
#define InvalidIdx -1  /* Indeks tak terdefinisi */

/* Definisi elemen dan koleksi objek */
#define IdxType int

typedef struct {
	Word A[MaxElStatic];  /* Memori tempat penyimpanan elemen (container) */
} StaticList;

#define List(i) L.A(i)

/* Indeks yang digunakan seberapa banyak memori itu terisi */
/* Jika L adalah List, cara deklarasi dan akses: */
/* Deklarasi: L : List */
/* Maka cara akses:
 * L.A untuk mengakses seluruh nilai elemen list
 * L.A[i] untuk mengakses elemen ke-i */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
void CreateEmptyStatic(StaticList *list);
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsEmptyStatic(StaticList list);
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

boolean IsFullStatic(StaticList list);
/* Mengirimkan true jika list L penuh, mengirimkan false jika tidak */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthStatic(StaticList list);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Menghasilkan sebuah elemen *** */
Word GetStatic(StaticList list, IdxType i);
/* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen list yang ke-i */



void InsertLastStatic(StaticList *list, Word word);
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

#endif