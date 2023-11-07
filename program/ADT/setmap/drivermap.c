#include <stdio.h>
#include "map.h"

int main() {
    Map M;
    CreateEmptymap(&M);

    printf("Is map empty? %s\n", IsEmptymap(M) ? "Yes" : "No");
    printf("Is map full? %s\n", IsFullmap(M) ? "Yes" : "No");

    Word key1, key2, key3;
    Word value1, value2, value3;

    key1.Length = 4;
    key2.Length = 5;
    key3.Length = 6;

    value1.Length = 2;
    value2.Length = 3;
    value3.Length = 4;

    key1.TabWord[0] = 'a';
    key1.TabWord[1] = 'b';
    key1.TabWord[2] = 'c';
    key1.TabWord[3] = 'd';

    key2.TabWord[0] = 'x';
    key2.TabWord[1] = 'y';
    key2.TabWord[2] = 'z';
    key2.TabWord[3] = 'w';
    key2.TabWord[4] = 'v';

    key3.TabWord[0] = 'h';
    key3.TabWord[1] = 'e';
    key3.TabWord[2] = 'l';
    key3.TabWord[3] = 'l';
    key3.TabWord[4] = 'o';
    key3.TabWord[5] = '!';

    value1.TabWord[0] = '1';
    value1.TabWord[1] = '0';
    value1.TabWord[2] = '\0';

    value2.TabWord[0] = '2';
    value2.TabWord[1] = '0';
    value2.TabWord[2] = '2';

    value3.TabWord[0] = '3';
    value3.TabWord[1] = '0';
    value3.TabWord[2] = '3';
    value3.TabWord[3] = '3';

    Insertmap(&M, key1, value1);
    Insertmap(&M, key2, value2);

    printf("Is map empty? %s\n", IsEmptymap(M) ? "Yes" : "No");
    printf("Is map full? %s\n", IsFullmap(M) ? "Yes" : "No");

    printf("Value for key 'abcd': %s\n", Valuemap(M, key1).TabWord);
    printf("Value for key 'xyzwv': %s\n", Valuemap(M, key2).TabWord);
    printf("Value for key 'hello!': %s\n", Valuemap(M, key3).TabWord);

    Deletemap(&M, key2);

    printf("Is 'xyzwv' in map after deletion? %s\n", IsMembermap(M, key2) ? "Yes" : "No");
    printf("Value for key 'xyzwv': %s\n", Valuemap(M, key2).TabWord);

    return 0;
}