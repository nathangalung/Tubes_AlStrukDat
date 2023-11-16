/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __WORD_MACHINE_H__
#define __WORD_MACHINE_H__

#include "charmachine.h"

/* State Mesin Kata */

boolean EndWord;
Word currentWord;

void IgnoreMarks();

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreNewlines();

void StartWordMark();

void StartWordBlank();

void StartWordNewline(Word filename);
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void AdvWordMark();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void AdvWordBlank();

void AdvWordNewline();

void CopyWordBlank();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWordMark();

void CopyWordNewline();

void DisplayWord(Word word);

int WordToInt(Word word);

Word StringToWord(char *s);

Word SplitWord(Word word);

boolean CompareWord2(Word word_1, Word word_2);\

Word ReadNameLine();

int ReadCountWord();

int ReadCountLine();

Word ConcatWord(Word word_1, Word word_2);

boolean CompareStringWord(Word word_1, char *string);

#endif