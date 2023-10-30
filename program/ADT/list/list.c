/* FILE list.c */

#include <stdio.h>
#include "list.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void CreateEmptyList(TabInt *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
  T->Neff = 0;
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
  return T.Neff;
}

int MaxNbEl(TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
{
  return IdxMax;
}

IdxType GetFirstIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
  return IdxMin;
}

IdxType GetLastIdx(TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
{
  return T.Neff;
}

ElType GetElmt(TabInt T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
  return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab(TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
  /* KAMUS LOKAL*/
  int i;
  /* ALGORITMA */
  for (i = IdxMin; i <= Tin.Neff; i++)
  {
    Tout->TI[i] = Tin.TI[i];
  }
  Tout->Neff = Tin.Neff;
}

void SetEl(TabInt *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
  /* KAMUS LOKAL */
  /* ALGORITMA */
  // printf("first idx %d last idx %d and idx is %d\n", GetFirstIdx(*T), GetLastIdx(*T), i);
    // Mapping dari Index Min yang program (1) menjadi Index Min asli (0)
    // printf("i: %d v: %d\n", i, v);
  T->TI[i] = v;
  if (i == GetLastIdx(*T) + 1)
  {
    T->Neff++;
  }
}

void SetNeff(TabInt *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
  T->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
  return (IdxMin <= i && i <= IdxMax);
}

boolean IsIdxEff(TabInt T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
  return (GetFirstIdx(T) <= i && i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyList(TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
{
  return (NbElmt(T) == 0);
}

boolean IsFullList(TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
  return (NbElmt(T) == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsiList(TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
1:1
2:2
3:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{
  /* KAMUS LOKAL */
  int i;
  /* ALGORITMA */
  if (IsEmpty(T))
  {
    printf("Tabel kosong\n");
  }
  else
  {
    for (i = GetFirstIdx(T); i <= GetLastIdx(T); i++)
    {
      printf("%d:%d\n", i, GetElmt(T, i));
    }
  }
}