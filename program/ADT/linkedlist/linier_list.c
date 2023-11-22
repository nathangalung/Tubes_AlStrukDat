#include <stdio.h>
#include <stdlib.h>

#include "linier_list.h"

boolean IsEmptyLinier (LinierList L)
{
	return (First(L) == Nil); 
}
void CreateEmptyLinier (LinierList *L)
{
	First(*L) = Nil;
}

address Alokasi (Word word)
{
	address P;
	P = (ElmtList *)malloc(sizeof(ElmtList));
	if (P != Nil)
	{
		Info(P) = word;
		Next(P) = Nil;
		return P;
	}
	else
	{
		return Nil;
	}
}

void Dealokasi (address *P)
{
	free(*P);
}

address SearchAdress (LinierList L, Word word)
{
	address P = First(L);
	boolean found = false;

	while (P != Nil && !found)
	{
		if (CompareWord(Info(P), word))
		{
			found = true;
		}
		else
		{
			P = Next(P); 
		}
	}

	if (found)
	{
		return P;
	}
	else
	{
		return Nil;
	}
}

boolean Search (LinierList L, Word word)
{
	address P = First(L);
	boolean found = false;

	while (P != Nil && !found)
	{
		if (CompareWord(Info(P), word))
		{
			return true;
		}
		else
		{
			P = Next(P); 
		}
	}
	return false;
}

void InsVFirst (LinierList *L, Word word)
{
	address P = Alokasi(word);

	if (P != Nil)
	{
		Next(P) = First(*L);
		First(*L) = P;
	}
}

void InsVLast (LinierList *L, Word word)
{
	address P = Alokasi(word);

	if (P != Nil)
	{
		InsertLast(L, P);
	}
}

void DelVFirst (LinierList *L, Word *word)
{
	address P;
	DelFirst(L, &P);
	(*word) = Info(P);
	Dealokasi(&P);
}

void DelVLast (LinierList *L, Word *word)
{
	address P;
	DelLast(L, &P);
	(*word) = Info(P);
	Dealokasi(&P);
}

void InsertFirst (LinierList *L, address P)
{
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (LinierList *L, address P, address Prec)
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast (LinierList *L, address P)
{
	if (IsEmptyLinier(*L))
	{
		InsertFirst(L, P);
	}
	else
	{
		address last = First(*L);
		while (Next(last) != Nil)
		{
			last = Next(last);
		}
		InsertAfter(L, P, last);
	}
}

void DelFirst (LinierList *L, address *P)
{
	*P = First(*L);
	First(*L) = Next(*P);
	Next(*P) = Nil;
}

void DelP (LinierList *L, Word word)
{
	address P = SearchAdress(*L, word);

	if (P != Nil)
	{
		if (P == First(*L))
		{
			DelFirst(L, &P);
		}
		else
		{
			address prec = First(*L);
			while (Next(prec) != P)
			{
				prec = Next(prec);
			}
			DelAfter(L, &P, prec);
		}
	}
}

void DelLast (LinierList *L, address *P)
{
	address last = First(*L);
	address prec = Nil;

	while (Next(last) != Nil)
	{
		prec = last;
		last = Next(last);
	}

	*P = last;
	if (prec == Nil)
	{
		First(*L) = Nil; 
	}
	else
	{
		Next(prec) = Nil;
	}
}

void DelAfter (LinierList *L, address *Pdel, address Prec)
{
	*Pdel = Next(Prec);
	if (Next(Prec) != Nil)
	{
		Next(Prec) = Next(Next(Prec));
		Next(*Pdel) = Nil;
	}
}

int NbElmt (LinierList L)
{
	int count = 0;

	address P = First(L);

	while (P != Nil)
	{
		P = Next(P);
		count++;
	}

	return count;
}

void InversLinierList (LinierList *L)
{
	address P = First(*L);
	address A = P;
	address B = Next(P);
	
	while (B != Nil)
	{
		A = B;
		B = Next(B);
		InsertFirst(L, A);
		Next(P) = B;
	}
}

void Konkat1 (LinierList *L1, LinierList *L2, LinierList *L3)
{
	CreateEmptyLinier(L3);
	address lastL1 = First(*L1);

	if (IsEmptyLinier(*L1))
	{
		First(*L3) = First(*L2);
	}
	else
	{
		First(*L3) = First(*L1);
		while (Next(lastL1) != Nil)
		{
			lastL1 = Next(lastL1);
		}
		Next(lastL1) = First(*L2);
	}

	CreateEmptyLinier(L1);
	CreateEmptyLinier(L2);
}