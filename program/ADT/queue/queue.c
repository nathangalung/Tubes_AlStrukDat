/* File queue.c */

#include "queue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isQueueEmpty(Queue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return ((IDX_HEAD(q) == IDX_UNDEF) && (IDX_TAIL(q) == IDX_UNDEF));
}

boolean isQueueFull(Queue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu ketika IDX_HEAD=0 dan IDX_TAIL=CAPACITY-1 */
    return (length(q) == CAPACITY-1);
}

int lengthQueue(Queue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    /* KAMUS LOKAL */
    int length;

    /* ALGORITMA */
    if (isEmpty(q)) {
        length = 0;
    } else if (IDX_TAIL(q) >= IDX_HEAD(q)){ /*Ketika tail berada di belakang head*/
        length = (IDX_TAIL(q) - IDX_HEAD(q)) + 1;
    } else { /*Ketika tail berada di depan head*/
        length = (IDX_TAIL(q) - IDX_HEAD(q)) + (CAPACITY + 1);
    }

    return length;
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    if (isEmpty(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    } else {
        int i;
        if (IDX_HEAD(*q) != 0) { /* Ketika tail sudah berada di posisi paling terakhir, tetapi array belum full, maka tail akan maju ke index awal yakni 0*/
            for (i=IDX_HEAD(*q); i <= IDX_TAIL(*q); i++) {
                (*q).buffer[i - IDX_HEAD(*q)] = (*q).buffer[i];
            }
            IDX_TAIL(*q) += 1;
        } else if (IDX_TAIL(*q) == CAPACITY-1) {
            IDX_TAIL(*q) += 1;
        } else {
            IDX_TAIL(*q) += 1;
        }
    } 
    TAIL(*q) = val;
}

void dequeue(Queue *q, ElType *val){
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)) {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF; 
    } else {
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q){
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
    if (isEmpty(q)){
        printf("[]\n");
    } else {
        int i;
        printf("[");
        if (IDX_HEAD(q) > IDX_TAIL(q)){
            for (i=IDX_HEAD(q); i <= CAPACITY-1; i++){
                printf("%d", q.buffer[i]);
                printf(",");
            } for (i=0; i <= IDX_TAIL(q); i++){
                printf("%d", q.buffer[i]);
                if (i != IDX_TAIL(q)) {
                    printf(",");
                }
            }
        } else {
            for (i=IDX_HEAD(q); i <= IDX_TAIL(q); i++){
                printf("%d", q.buffer[i]);
                if (i != IDX_TAIL(q)) {
                    printf(",");
                }
            }
        } printf("]\n");
    }
}