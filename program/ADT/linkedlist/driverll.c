#include <stdio.h>
#include "linier_list.h"

void printll(LinierList L){
    address p=First(L);
    if(IsEmptyLinier(L)){
        printf("[]\n");
    }
    else{
    printf("[");
    for(int i=0; i<NbElmt(L);i++){
    if(i==NbElmt(L)-1){
        printf("%s]\n", Info(p).TabWord);
    }
    else{
    printf("%s, ", Info(p).TabWord);
    p=Next(p);}}
    }

}

int main() {
    LinierList L1, L2, L3;
    Word word;
    address P;

    // Inisialisasi list
    CreateEmptyLinier(&L1);
    CreateEmptyLinier(&L2);
    CreateEmptyLinier(&L3);

    // Menambahkan elemen ke list
    InsVFirst(&L1, StringToWord("apple"));
    InsVLast(&L1, StringToWord("banana"));
    InsVLast(&L1, StringToWord("cherry"));

    printf("List L1:\n");
    printll(L1);

    // Mencari elemen dalam list
    word = StringToWord("banana");
    if (Search(L1, word)) {
        printf("'%s' ditemukan dalam list L1\n", word.TabWord);
    } else {
        printf("'%s' tidak ditemukan dalam list L1\n", word.TabWord);
    }

    // Menghapus elemen dari list
    DelVFirst(&L1, &word);
    printf("Elemen pertama dihapus: '%s'\n", word.TabWord);

    printf("List L1 setelah menghapus elemen pertama:\n");
    printll(L1);

    // Membuat list terbalik
    InversLinierList(&L1);
    printf("List L1 setelah dibalik:\n");
    printll(L1);

    // Menggabungkan dua list
    InsVLast(&L2, StringToWord("grape"));
    InsVLast(&L2, StringToWord("kiwi"));

    printf("List L2:\n");
    printll(L2);

    Konkat1(&L1, &L2, &L3);
    printf("List L3 setelah menggabungkan L1 dan L2:\n");
    printll(L3);

    // Membersihkan list
    DelVLast(&L3, &word);
    printf("Elemen terakhir dihapus dari list L3: '%s'\n", word.TabWord);

    return 0;
}