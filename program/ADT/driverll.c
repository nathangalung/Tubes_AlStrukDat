#include <stdio.h>
#include "listlinier.h"

int main() {
    List l;
    CreateList(&l);

    // InsertFirst, InsertLast, InsertAt
    Word val1, val2, val3, val4, val5;

    // Set elements manually and calculate their lengths
    val1.Length = 5;
    val1.TabWord[0] = 'a';
    val1.TabWord[1] = 'p';
    val1.TabWord[2] = 'p';
    val1.TabWord[3] = 'l';
    val1.TabWord[4] = 'e';
    insertLast(&l, val1);

    val2.Length = 6;
    val2.TabWord[0] = 'b';
    val2.TabWord[1] = 'a';
    val2.TabWord[2] = 'n';
    val2.TabWord[3] = 'a';
    val2.TabWord[4] = 'n';
    val2.TabWord[5] = 'a';
    insertLast(&l, val2);

    val3.Length = 6;
    val3.TabWord[0] = 'c';
    val3.TabWord[1] = 'h';
    val3.TabWord[2] = 'e';
    val3.TabWord[3] = 'r';
    val3.TabWord[4] = 'r';
    val3.TabWord[5] = 'y';
    insertLast(&l, val3);

    val4.Length = 4;
    val4.TabWord[0] = 'd';
    val4.TabWord[1] = 'a';
    val4.TabWord[2] = 't';
    val4.TabWord[3] = 'e';
    insertFirst(&l, val4);

    val5.Length = 3;
    val5.TabWord[0] = 'f';
    val5.TabWord[1] = 'i';
    val5.TabWord[2] = 'g';
    insertAt(&l, val5, 2);

    // Display List
    printf("List: ");
    displayList(l);
    printf("\n");

    // GetElmt and SetElmt
    Word wordVal = getElmt(l, 2);
    printf("Element at index 2: ");
    for (int i = 0; i < wordVal.Length; i++) {
        printf("%c", wordVal.TabWord[i]);
    }
    printf("\n");

    // Modify element at index 2 manually
    val2.Length = 5;
    val2.TabWord[0] = 'g';
    val2.TabWord[1] = 'r';
    val2.TabWord[2] = 'a';
    val2.TabWord[3] = 'p';
    val2.TabWord[4] = 'e';
    setElmt(&l, 2, val2);

    // Display List after setting element at index 2
    printf("Updated List: ");
    displayList(l);
    printf("\n");

    // Length
    printf("Length of the list: %d\n", length(l));

    // Search and SearchPrec
    Word searchVal;

    // Set search value manually
    searchVal.Length = 6;
    searchVal.TabWord[0] = 'c';
    searchVal.TabWord[1] = 'h';
    searchVal.TabWord[2] = 'e';
    searchVal.TabWord[3] = 'r';
    searchVal.TabWord[4] = 'r';
    searchVal.TabWord[5] = 'y';

    Address result = searchPrec(l, searchVal);
    if (result != NULL) {
        printf("Search result: Found\n");
    } else {
        printf("Search result: Not Found\n");
    }

    // DeleteFirst and DeleteLast
    deleteFirst(&l, &wordVal);
    deleteLast(&l, &wordVal);

    // Display List after deletions
    printf("List after deleteFirst and deleteLast: ");
    displayList(l);
    printf("\n");

    // InverseList
    inverseList(&l);
    printf("List after inverse: ");
    displayList(l);
    printf("\n");

    // SplitList
    List l1, l2;
    CreateList(&l1);
    CreateList(&l2);

    splitList(&l1, &l2, l);

    printf("l1 after split: ");
    displayList(l1);
    printf("\n");

    printf("l2 after split: ");
    displayList(l2);
    printf("\n");

    // Concat
    List l3 = concat(l1, l2);
    printf("l3 after concatenation of l1 and l2: ");
    displayList(l3);
    printf("\n");

    // DeleteAll
    deleteAll(&l3);
    printf("l3 after deleteAll: ");
    displayList(l3);
    printf("\n");

    return 0;
}