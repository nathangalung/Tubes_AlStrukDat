#ifndef set_H
#define set_H
#include <stdio.h>
#include "../boolean.h"
#include "wordmachine.h"

/* MODUL Set
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

#define Nil 0
#define MaxEl 100

typedef Word infotype;
typedef int address;

typedef struct
{
    infotype Elements[MaxEl];
    address Count;
} Set;

/* Definisi Set S kosong : S.Count = Nil */
/* S.Count = jumlah element Set */
/* S.Elements = tempat penyimpanan element Set */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyset(Set *S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyset(Set S);
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFullset(Set S);
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insertset(Set *S, infotype Elmt);
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Deleteset(Set *S, infotype Elmt);
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMemberset(Set S, infotype Elmt);
/* Mengembalikan true jika Elmt adalah member dari S */

#endif