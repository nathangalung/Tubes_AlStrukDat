#include <stdio.h>
#include "set.h"

boolean IsStringsEqual(const char str1[], const char str2[]) {
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return false;
        }
        i++;
    }

    // Pastikan keduanya berakhir pada karakter null.
    if (str1[i] != '\0' || str2[i] != '\0') {
        return false;
    }

    return true;
}
/* *** Konstruktor/Kreator *** */
void CreateEmptyset(Set *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */
{
    (*S).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyset(Set S)
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */
{
    return S.Count == Nil;
}

boolean IsFullset(Set S)
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */
{
    return S.Count == MaxEl;
}

/* ********** Operator Dasar Set ********* */
void Insertset(Set *S, infotype Elmt)
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */
{
    if (!IsMemberset(*S, Elmt)) {
        (*S).Elements[(*S).Count] = Elmt;
        (*S).Count++;
    }
}

void Deleteset(Set *S, infotype Elmt)
/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */
{
    int i = 0;
    boolean found = false;

    // Cari indeks Elmt di dalam Set
    while (i < (*S).Count && !found)
    {
        if (IsStringsEqual((*S).Elements[i].TabWord, Elmt.TabWord))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    if (found) {
        // Geser elemen-elemen berikutnya untuk menggantikan Elmt
        for (int j = i; j < (*S).Count - 1; j++)
        {
            (*S).Elements[j] = (*S).Elements[j + 1];
        }

        // Kurangi jumlah elemen di dalam Set
        (*S).Count--;
    }
}

boolean IsMemberset(Set S, infotype Elmt)
/* Mengembalikan true jika Elmt adalah anggota dari Set S */
{
    for (int i = 0; i < S.Count; i++)
    {
        if (IsStringsEqual(S.Elements[i].TabWord, Elmt.TabWord))
        {
            return true;
        }
    }

    return false;
}