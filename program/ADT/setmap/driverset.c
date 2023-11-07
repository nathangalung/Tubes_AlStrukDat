#include <stdio.h>
#include "set.h"

int main() {
    Set S;
    CreateEmptyset(&S);

    printf("Is set empty? %s\n", IsEmptyset(S) ? "Yes" : "No");
    printf("Is set full? %s\n", IsFullset(S) ? "Yes" : "No");

    Word word1, word2, word3;
    word1.Length = 4;
    word2.Length = 5;
    word3.Length = 6;

    word1.TabWord[0] = 'a';
    word1.TabWord[1] = 'b';
    word1.TabWord[2] = 'c';
    word1.TabWord[3] = 'd';

    word2.TabWord[0] = 'x';
    word2.TabWord[1] = 'y';
    word2.TabWord[2] = 'z';
    word2.TabWord[3] = 'w';
    word2.TabWord[4] = 'v';

    word3.TabWord[0] = 'h';
    word3.TabWord[1] = 'e';
    word3.TabWord[2] = 'l';
    word3.TabWord[3] = 'l';
    word3.TabWord[4] = 'o';
    word3.TabWord[5] = '!';

    Insertset(&S, word1);
    Insertset(&S, word2);

    printf("Is set empty? %s\n", IsEmptyset(S) ? "Yes" : "No");
    printf("Is set full? %s\n", IsFullset(S) ? "Yes" : "No");

    printf("Is 'abcd' in set? %s\n", IsMemberset(S, word1) ? "Yes" : "No");
    printf("Is 'xyzwv' in set? %s\n", IsMemberset(S, word2) ? "Yes" : "No");
    printf("Is 'hello!' in set? %s\n", IsMemberset(S, word3) ? "Yes" : "No");

    Deleteset(&S, word2);

    printf("Is 'xyzwv' in set after deletion? %s\n", IsMemberset(S, word2) ? "Yes" : "No");
    printf("Is 'xyzwv' in set? %s\n", IsMemberset(S, word2) ? "Yes" : "No");
    return 0;
}