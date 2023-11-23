/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "../machine/wordmachine.h"


#define IDX_UNDEF -1
#define MaxElQueue 100

/* Definisi elemen dan address */
typedef struct {
	Word Buffer[MaxElQueue]; 
	int IDXHead;
	int IDXTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(queue) (queue).IDXHead
#define IDX_TAIL(queue) (queue).IDXTail
#define     HEAD(queue) (queue).Buffer[(queue).IDXHead]
#define     TAIL(queue) (queue).Buffer[(queue).IDXTail]

/* *** Kreator *** */
void CreateEmptyQueue(Queue *queue);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean IsEmptyQueue(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */

boolean IsFullQueue(Queue queue);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/

boolean IsMemberQueue(Queue queue, int index);
/* Mengirim true apabila index lagu ada di dalam queue. */

int LengthQueue(Queue queue);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void Enqueue(Queue *queue, Word word);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void Dequeue(Queue *queue, Word *word);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

#endif