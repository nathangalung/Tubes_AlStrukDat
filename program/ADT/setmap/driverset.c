#include <stdio.h>
#include "set.h"

int main() {
    Set mySet;
    CreateEmptySet(&mySet);

    printf("Is set empty? %s\n", IsEmptySet(mySet) ? "Yes" : "No");
    printf("Is set full? %s\n", IsFullSet(mySet) ? "Yes" : "No");

    Word element1, element2, element3;
    StringToWord("element1");
    StringToWord("element2");
    StringToWord("element3");

    InsertSet(&mySet, element1);
    InsertSet(&mySet, element2);

    printf("Is set empty? %s\n", IsEmptySet(mySet) ? "Yes" : "No");
    printf("Is set full? %s\n", IsFullSet(mySet) ? "Yes" : "No");

    printf("Is element1 a member of the set? %s\n", IsMemberSet(mySet, element1) ? "Yes" : "No");
    printf("Is element3 a member of the set? %s\n", IsMemberSet(mySet, element3) ? "Yes" : "No");

    DeleteSet(&mySet, element1);

    printf("Is element1 a member of the set? %s\n", IsMemberSet(mySet, element1) ? "Yes" : "No");

    return 0;
}