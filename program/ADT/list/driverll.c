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
    LinierList myList;
    Word word1 = {"apple",5};
    Word word2 = {"banana",6};
    Word word3 = {"cherry",6};
    Word word4 = {"grape",5};

    // Test CreateEmptyLinier, IsEmptyLinier
    CreateEmptyLinier(&myList);
    printf("Is the list empty? %s\n", IsEmptyLinier(myList) ? "Yes" : "No");

    // Test InsVFirst, InsVLast
    InsVFirst(&myList, word1);
    InsVLast(&myList, word2);
    InsVLast(&myList, word3);
    InsVLast(&myList, word4);

    // Test NbElmt
    printf("Number of elements in the list: %d\n", NbElmt(myList));

    // Test SearchLinier
    Word searchWord = {"banana",6};
    printf("Is '%s' in the list? %s\n", searchWord.TabWord, SearchLinier(myList, searchWord) ? "Yes" : "No");

    // Test DelP
    DelP(&myList, word2);
    printf("After deleting '%s', the number of elements: %d\n", word2.TabWord, NbElmt(myList));

    // Test InversLinierList
    InversLinierList(&myList);
    printf("After inverting the list, the number of elements: %d\n", NbElmt(myList));

    // Test DelVLast
    Word deletedWord;
    DelVLast(&myList, &deletedWord);
    printf("Deleted last element with value: %s\n", deletedWord.TabWord);

    // Test DelVFirst
    DelVFirst(&myList, &deletedWord);
    printf("Deleted first element with value: %s\n", deletedWord.TabWord);

    // Print the final state of the list
    printf("Final state of the list:\n");
    address current = First(myList);
    int i=1;
    while (current != Nil) {
        printf("%d. %s\n", i,Info(current).TabWord);
        current = Next(current);
        i++;
    }

    return 0;
}
