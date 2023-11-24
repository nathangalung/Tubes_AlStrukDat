/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __WORD_MACHINE_H__
#define __WORD_MACHINE_H__

#include "charmachine.h"
#include "../list/static_list.h"

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

boolean StartWordNewline(Word filename);
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
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin BLANK
          Jika currentChar = BLANK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void AdvWordNewline();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin NEWLINE
          Jika currentChar = NEWLINE, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWordBlank();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWordMark();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void CopyWordNewline();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = NEWLINE;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

void DisplayWord(Word word);
/* Mengeluarkan isi dari word.TabWord sebagai suatu string */

boolean CompareWord(Word word_1, Word word_2);
/* Membandingkan isi string antara word_1 dengan word_2*/

boolean CompareStringWord(Word word_1, char *string);
/* Membandingkan isi string antara word_1 dengan suatu string */

int WordToInt(Word word);
/* Mengubah Word menjadi suatu integer */

Word StringToWord(char *s);
/* Mengubah string menjadi suatu Word*/

void WordToString(Word word, char *string);
/* Mengubah Word menjadi suatu string*/

Word SplitWordMark(Word word);
/* Memisahkan sebuah word menjadi dua word dengan batasan MARK dan dikeluarkan hanya word bagian kanan/kedua */

Word SplitWordBlank(Word word);
/* Memisahkan sebuah word menjadi dua word dengan batasan BLANK dan dikeluarkan hanya word bagian kanan/kedua */

Word SplitWordLeftMark(Word word);
/* Memisahkan sebuah word menjadi dua word dengan batasan MARK dan dikeluarkan hanya word bagian kiri/pertama */

Word SplitWordLeftBlank(Word word);
/* Memisahkan sebuah word menjadi dua word dengan batasan BLANK dan dikeluarkan hanya word bagian kiri/pertama */

Word ConcatWord(Word word_1, Word word_2);
/* Menggabungkan dua buah word menjadi sebuah word*/

Word ReadNameLine();
/* Membaca suatu baris file konfigurasi dan mengubah menjadi suatu struktur Word*/

int ReadCountWord();
/* Membaca suatu kata file konfigurasi dan mengubah menjadi suatu integer*/

int ReadCountLine();
/* Membaca suatu baris file konfigurasi dan mengubah menjadi suatu integer*/

#endif