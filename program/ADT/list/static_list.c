/* file static_list.c */

#include <stdio.h>
#include "static_list.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong */
StaticList MakeStaticList()
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */
{
    /* KAMUS LOKAL */
    int i;
    List L;

    /* ALGORITMA */
    for (i = FirstIdxList(L); i <= LastIdxList(L); i++)
    {
        L.A[i] = Mark;
    }
    return L;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsListEmpty(StaticList L)
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */
{
    return (LengthList(L) == 0);
}

/* *** Menghasilkan sebuah elemen *** */
ElType Get(StaticList L, IdxType i)
/* Prekondisi : list tidak kosong, i antara FirstIdxList(L)..LastIdxList(L) */
/* Mengirimkan elemen list yang ke-i */
{
    return (L.A[i]);
}

/* *** Selektor SET : Mengubah nilai list dan elemen list *** */
void Set(StaticList *L, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
{
    L->A[i] = v;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthList(StaticList L)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */
{
    /* KAMUS LOKAL */
    int i, count = 0;

    /* ALGORITMA */
    for (i = FirstIdxList(L); i <= LastIdxList(L); i++)
    {
        if (L.A[i] != Mark)
        {
            count++;
        }
    }
    return count;
}

/* *** Selektor INDEKS *** */
IdxType FirstIdxList(StaticList L)
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return 0;
}

IdxType LastIdxList(StaticList L)
/* Prekondisi : list L tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
    /* KAMUS LOKAL */
    int i = FirstIdxList(L);

    /* ALGORITMA */
    while (i <= MaxEl - 1 && L.A[i] != Mark)
    {
        i++;
    }
    return i - 1;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxListValid(StaticList L, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid untuk ukuran list */
/* yaitu antara indeks yang terdefinisi untuk container */
{
    return (FirstIdxList(L) <= i && i <= LastIdxList(L));
}

boolean IsIdxListEff(StaticList L, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang terdefinisi untuk list */
/* yaitu antara FirstIdxList(L)..LastIdxList(L) */
{
    return (FirstIdxList(L) <= i && i <= LastIdxList(L) && L.A[i] != Mark);
}

/* ********** Operasi-operasi ********** */
boolean SearchList(StaticList L, ElType X)
/* Prekondisi : X sembarang */
/* Mengirimkan true jika terdapat elemen X di dalam list */
/* yaitu antara FirstIdxList(L)..LastIdxList(L) */
{
    /* KAMUS LOKAL */
    int i = FirstIdxList(L);
    boolean ketemu = false;

    /* ALGORITMA */
    while (i <= LastIdxList(L) && ketemu == false)
    {
        if (L.A[i] == X)
        {
            ketemu = true;
        }
        i++;
    }
    return ketemu;
}

void InsertFirstList(StaticList *L, ElType X)
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */
{
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    if (LengthList(*L) < MaxEl)
    {
        for (i = LastIdxList(*L); i >= FirstIdxList(*L); i--)
        {
            L->A[i + 1] = L->A[i];
        }
        L->A[FirstIdxList(*L)] = X;
    }
}

void InsertListAt(StaticList *L, ElType X, IdxType i)
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks logik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */
{
    /* KAMUS LOKAL */
    int j;

    /* ALGORITMA */
    if (LengthList(*L) < MaxEl && IsIdxListEff(*L, i))
    {
        for (j = LastIdxList(*L); j >= i; j--)
        {
            L->A[j + 1] = L->A[j];
        }
        L->A[i] = X;
    }
}

void InsertLastList(StaticList *L, ElType X)
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */
{
    /* KAMUS LOKAL */
    /* ALGORITMA */
    if (LengthList(*L) < MaxEl)
    {
        L->A[LengthList(*L)] = X;
    }
}

void DeleteFirstList(StaticList *L)
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */
{
    /* KAMUS LOKAL */
    int i;

    /* ALGORITMA */
    if (!IsListEmpty(*L))
    {
        for (i = FirstIdxList(*L); i < LastIdxList(*L); i++)
        {
            L->A[i] = L->A[i + 1];
        }
        L->A[LastIdxList(*L)] = Mark;
    }
}

void DeleteListAt(StaticList *L, IdxType i)
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks logik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
{
    /* KAMUS LOKAL */
    int j;

    /* ALGORITMA */
    if (!IsListEmpty(*L) && IsIdxListEff(*L, i))
    {
        for (j = i; j < LastIdxList(*L); j++)
        {
            L->A[j] = L->A[j + 1];
        }
        L->A[LastIdxList(*L)] = Mark;
    }
}

void DeleteLastList(StaticList *L)
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */
{
    if (!IsListEmpty(*L))
    {
        L->A[LastIdxList(*L)] = Mark;
    }
}

List ConcatList(StaticList L1, StaticList L2)
/* Prekondisi : L1 dan L2 tidak kosong */
/* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
/* Urutan elemen terisi dari L1, lalu L2 */
/* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */
{
    /* KAMUS LOKAL */
    List L = MakeList();
    int i = FirstIdxList(L1), j = FirstIdxList(L2);

    /* ALGORITMA */
    while (i <= LastIdxList(L1) && L1.A[i] != Mark)
    {
        InsertLastList(&L, L1.A[i]);
        i++;
    }
    while (j <= LastIdxList(L2) && L2.A[j] != Mark)
    {
        InsertLastList(&L, L2.A[j]);
        j++;
    }
    return L;
}