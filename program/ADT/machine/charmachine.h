/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __CHAR_MACHINE_H_
#define __CHAR_MACHINE_H_

#include "../../boolean.h"


#define MARK ';'
#define BLANK ' '
#define NEWLINE '\n'

#define NMaxWord 150

typedef struct
{
   char TabWord[NMaxWord]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin */
extern char currentChar;
extern boolean EOP;

void StartMark();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void StartBlank();

boolean StartNewline(Word filename);

void AdvMark();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void AdvBlank();

void AdvNewline();

/* Mengirimkan currentChar */

boolean IsEOPMark();
/* Mengirimkan true jika currentChar = MARK */

boolean IsEOPBlank();

boolean IsEOPNewline();

boolean CompareWord(Word word_1, Word word_2);

#endif