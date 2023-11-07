#include <stdio.h>
#include "map.h"

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
void CreateEmptymap(Map *M)
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
{
    (*M).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptymap(Map M)
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
{
    return M.Count == Nil;
}

boolean IsFullmap(Map M)
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
{
    return M.Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */
valuetype Valuemap(Map M, keytype k)
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
{
    for (int i = 0; i < M.Count; i++)
    {
        if (IsStringsEqual(M.Elements[i].Key.TabWord, k.TabWord))
        {
			return M.Elements[i].Value;
		}
    }

    // Jika key tidak ditemukan, kembalikan nilai Word yang sesuai
    Word notFound;
    const char notFoundMessage[] = "notFound";
    int j = 0;
    while (notFoundMessage[j] != '\0')
    {
        notFound.TabWord[j] = notFoundMessage[j];
        j++;
    }
    notFound.TabWord[j] = '\0';
    notFound.Length = j;

    return notFound;
}

void Insertmap(Map *M, keytype k, valuetype v)
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
{
    if (!IsMembermap((*M), k))
    {
        (*M).Elements[(*M).Count].Key = k;
        (*M).Elements[(*M).Count].Value = v;
        (*M).Count += 1;
    }
}

void Deletemap(Map *M, keytype k)
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
{
    if (IsMembermap((*M), k))
    {
        boolean found = false;
        int i = 0;

        while (i < (*M).Count && !found)
        {
            if (IsStringsEqual((*M).Elements[i].Key.TabWord, k.TabWord))
            {
                found = true;
                for (i = i; i < (*M).Count - 1; i++)
                {
                    (*M).Elements[i] = (*M).Elements[i + 1];
                }
                (*M).Count -= 1;
            }
            i += 1;
        }
    }
}

boolean IsMembermap(Map M, keytype k)
/* Mengembalikan true jika k adalah member dari M */
{
    for (int i = 0; i < M.Count; i++)
    {
        if (IsStringsEqual(M.Elements[i].Key.TabWord, k.TabWord))
        {
            return true;
        }
    }

    return false;
}